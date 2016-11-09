FROM centos:latest

RUN yum install -y gcc

RUN mkdir /work
ADD queue_w.c /work


