# Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
# Distributed under the terms of the GNU Affero General Public License v3

ACLOCAL_AMFLAGS = -Im4
AM_CPPFLAGS = -I$(srcdir)/src

theiaheadersdir = Entropy/Theia
theiaheaders_HEADERS = \
	src/Exception.hh \
	src/Window.hh \
	src/Array.hh \
	src/Bind.hh \
	src/Buffer.hh \
	src/Buffer.impl.hh \
	src/Program.hh \
	src/Shader.hh \
	src/Texture.hh \
	src/Object.hh \
	src/DefaultedList.hh \
	src/DefaultedList.impl.hh \
	src/Camera.hh

glfwheadersdir = Entropy/Theia/GLFW
glfwheaders_HEADERS = \
	src/GLFW/Glfw.hh \
	src/GLFW/Window.hh

lib_LTLIBRARIES = libtheia.la

libtheia_la_SOURCES = \
	src/GLFW/Glfw.cc \
	src/GLFW/Window.cc \
	src/Array.cc \
	src/Bind.cc \
	src/Buffer.cc \
	src/Program.cc \
	src/Shader.cc \
	src/Texture.cc \
	src/Object.cc \
	src/Camera.cc \
	src/Drawable.cc

check_PROGRAMS = \
	hand-window \
	hand-object \
	hand-camera

hand_window_SOURCES = test/hand/window.cc
hand_window_LDADD = libtheia.la

hand_object_SOURCES = test/hand/object.cc
hand_object_LDADD = libtheia.la

hand_camera_SOURCES = test/hand/camera.cc
hand_camera_LDADD = libtheia.la

if GTEST
check_PROGRAMS += \
	utility-defaulted-list

utility_defaulted_list_SOURCES = test/utility/defaulted-list.cc
utility_defaulted_list_LDADD = $(GTEST_LIBS) libtheia.la
endif

TESTSUITE = $(srcdir)/test/testsuite

TESTSUITE_FILES = \
	$(srcdir)/test/utility.at

EXTRA_DIST = $(TESTSUITE_FILES) \
	$(srcdir)/test/testsuite.at \
	$(srcdir)/package.m4 \
	$(TESTSUITE) \
	$(srcdir)/test/atlocal.in

$(srcdir)/package.m4: $(top_srcdir)/configure.ac
	:; {\
		echo '# Signature of the current package. (auto-generated)' && \
		echo 'm4_define([AT_PACKAGE_NAME],' && \
		echo '  [$(PACKAGE_NAME)])' && \
		echo 'm4_define([AT_PACKAGE_TARNAME],' && \
		echo '  [$(PACKAGE_TARNAME)])' && \
		echo 'm4_define([AT_PACKAGE_VERSION],' && \
		echo '  [$(PACKAGE_VERSION)])' && \
		echo 'm4_define([AT_PACKAGE_STRING],' && \
		echo '  [$(PACKAGE_STRING)])' && \
		echo 'm4_define([AT_PACKAGE_BUGREPORT],' && \
		echo '  [$(PACKAGE_BUGREPORT)])'; \
		echo 'm4_define([AT_PACKAGE_URL],' && \
		echo '  [$(PACKAGE_URL)])'; \
	} >'$(srcdir)/package.m4'

check-local: test/atconfig atlocal $(TESTSUITE) $(check_PROGRAMS)
	$(SHELL) '$(TESTSUITE)' AUTOTEST_PATH='$(shell pwd)' $(TESTSUITEFLAGS)

clean-local:
	test ! -f '$(TESTSUITE)' || \
		$(SHELL) '$(TESTSUITE)' --clean

AUTOM4TE = $(SHELL) $(srcdir)/build-aux/missing --run autom4te
AUTOTEST = $(AUTOM4TE) --language=autotest
$(TESTSUITE): $(srcdir)/test/testsuite.at $(TESTSUITE_FILES) $(srcdir)/package.m4
	$(AUTOTEST) -I '$(srcdir)/test' -I $(srcdir) -o $@.tmp $@.at
	mv $@.tmp $@
