FROM alpine:3

RUN apk add --no-cache build-base cmake

WORKDIR /build
COPY ./mod/* .
RUN cmake .

COPY ./testcases .
COPY ./docker-entrypoint.sh .
ENV SUBMIT_D=/submit
ENV TESTING=7
ENTRYPOINT ["sh", "-c", "/build/docker-entrypoint.sh"]
