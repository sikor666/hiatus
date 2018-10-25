FROM ubuntu:18.04

USER root

RUN apt-get -y update
RUN apt-get -y install cmake
RUN apt-get -y install g++
RUN apt-get -y install libboost-all-dev
