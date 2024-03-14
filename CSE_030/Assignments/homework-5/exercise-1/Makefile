# UCM Makefile for C++ projects
# Angelo Kyrilov

WORKDIR = $(shell pwd)

NOT_ALLOWED = 'stl_vector|stl_list|stl_deque|std_stack|stl_queue|stl_set|stl_map|unordered_map|unordered_set'
DEP = $(shell g++ -M main.cpp | grep -E $(NOT_ALLOWED))


build_config = '{\n\
"version": "0.2.0", \n\
"configurations": [\n\
{\n\
"type": "lldb",\n\
"request": "launch",\n\
"name": "Debug Current",\n\
"program": "$(WORKDIR)/$(1)",\n\
"args": [],\n \
"cwd": "$(WORKDIR)"\n\
}\n\
]\n\
}'

CONFIG_FILE = ~/workspace/.theia/launch.json

all:
ifneq ($(DEP),)
	@echo
	@echo Your project includes headers that are not allowed
	@echo Use \"make force\" to attempt the build anyway
	@echo
	@false
endif
	g++ main.cpp -g -I. -o app
	@echo $(call build_config,app) > $(CONFIG_FILE)

force:
	g++ main.cpp -g -I. -o app
	@echo $(call build_config,app) > $(CONFIG_FILE)

.PHONY: test
test:
ifneq ($(DEP),)
	@echo
	@echo Your project includes headers that are not allowed
	@echo Use \"make force_test\" to attempt the test anyway
	@echo
	@false
endif
	g++ -g -I. test.cpp -o test
	clear && echo "Running all tests:" && ./test --output=color
	@echo $(call build_config,test) > $(CONFIG_FILE)

.PHONY: force_test
force_test:
	g++ -g -I. test.cpp -o test
	clear && echo "Running all tests:" && ./test --output=color
	@echo $(call build_config,test) > $(CONFIG_FILE)

clean:
	rm -f app
	rm -f test