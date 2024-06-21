#!/bin/sh

set -e

ID=${ID?'error: id not specified'}
INPUT_F=${INPUT_F?'error: input file not specified'}

echo -n "${INPUT_F},${ID}" > $SUBMIT_D/$ID.csv

# -- Trim

cp "$SUBMIT_D/$INPUT_F" tmp.cc

function trimer() {
  INPUT_F="$1"
  OUTPUT_F="$2"
  BEGIN_SIG="$3"
  END_SIG="$4"

  BEGIN_LN=$(grep -n "${BEGIN_SIG}" ${INPUT_F} | head -n 1 | cut -d ':' -f 1)
  tail -n +${BEGIN_LN} ${INPUT_F} > ${INPUT_F}.tmp

  END_LN=$(grep -n "${END_SIG}" ${INPUT_F}.tmp | head -n 1 | cut -d ':' -f 1)
  head -n ${END_LN} ${INPUT_F}.tmp > ${OUTPUT_F}
  rm *.tmp
}

trimer 'tmp.cc' 'stk.tmp.cc'  'int StackLinter::lint' '^}'
trimer 'tmp.cc' 'q.tmp.cc'    'int QueueLinter::lint' '^}'

cat << EOF > lv1_stack_linter.cc
#include "lv1_stack_linter.h"
using namespace std;
EOF

cat << EOF > lv2_queue_linter.cc
#include "lv2_queue_linter.h"
using namespace std;
EOF

cat stk.tmp.cc  >> lv1_stack_linter.cc
cat q.tmp.cc    >> lv2_queue_linter.cc

cp lv1_stack_linter.cc $SUBMIT_D/$ID.stacklinter.cc.tmp
cp lv2_queue_linter.cc $SUBMIT_D/$ID.queuelinter.cc.tmp

set +e

# -- Compile

echo '-- Building source'
if ! cmake --build .; then
  echo >> $SUBMIT_D/$ID.csv
  echo '-- failed.'
  exit 1
fi
echo '-- done.'

# -- Test

for i in $(seq 1 $TESTING); do
  echo "-- Testing t #$i"

  cat ex$i.stdin | ./lint 1> ans$i.stdout 2> ans$i.stderr
  echo "* process exited with $?"

  if `diff ex$i.stdout ans$i.stdout &> $SUBMIT_D/$ID.ex$i.diff.stdout`; then
    echo -n ,1 >> $SUBMIT_D/$ID.csv
    echo "* stdout matched"
  else
    echo -n ,0 >> $SUBMIT_D/$ID.csv
    echo "* stdout not matched"
  fi

  if `diff ex$i.stderr ans$i.stderr &> $SUBMIT_D/$ID.ex$i.diff.stderr`; then
    echo -n ,1 >> $SUBMIT_D/$ID.csv
    echo "* stderr matched"
  else
    echo -n ,0 >> $SUBMIT_D/$ID.csv
    echo "* stderr not matched"
  fi

  cp ans$i.stdout $SUBMIT_D/$ID.ex$i.stdout
  cp ans$i.stderr $SUBMIT_D/$ID.ex$i.stderr

  echo "-- done."
done
echo >> $SUBMIT_D/$ID.csv
