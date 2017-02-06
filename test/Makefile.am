
LDADD = ../src/libthread.la

check_PROGRAMS = \
  testmutex \
  testncpu

testmutex_SOURCES = testmutex.c
testncpu_SOURCES = testncpu.c

check:
	./testmutex$(EXEEXT)
	./testncpu$(EXEEXT)
