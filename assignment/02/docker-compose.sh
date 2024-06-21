#!/bin/sh

echo services: > docker-compose.yaml
for f in $(ls ./submissions/*.cc); do
INPUT_F=$(echo "$f" | sed 's|./submissions/||g')
ID=$(echo "$INPUT_F" | sed -E 's|(.*)([0-9]{4})[-_]?([0-9]{5})[_]?[aA](.+).cc|\2-\3|g')
cat << EOF >> docker-compose.yaml
  $ID:
    image: ghcr.io/haeramkeem/assignment-02.cp24s.cse.snu.ac.kr:latest
    volumes:
      - ./submissions:/submit
    environment:
      - ID=$ID
      - INPUT_F=$INPUT_F
EOF
done
