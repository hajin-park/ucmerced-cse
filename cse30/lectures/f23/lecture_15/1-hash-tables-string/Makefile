# UCM Makefile for C++ projects
# Angelo Kyrilov

WORKDIR = $(shell pwd)

NOT_ALLOWED = 'stl_vector|stl_list|stl_deque|std_stack|stl_queue|stl_set|stl_map|unordered_map|unordered_set|algorithmfwd.h'
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

CONFIG_FOLDER = ~/workspace/.theia/
CONFIG_FILE = ~/workspace/.theia/launch.json

SKIPTIME=0

all:
ifneq ($(DEP),)
	@echo
	@echo Your project includes headers that are not allowed
	@echo Use \"make force\" to attempt the build anyway
	@echo
	@false
endif
	g++ main.cpp -g -I. -o app
	@rm -rf $(CONFIG_FOLDER)
	@mkdir $(CONFIG_FOLDER)
	@echo $(call build_config,app) > $(CONFIG_FILE)

force:
	g++ main.cpp -g -I. -o app
	@rm -rf $(CONFIG_FOLDER)
	@mkdir $(CONFIG_FOLDER)
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
	@rm -rf $(CONFIG_FOLDER)
	@mkdir $(CONFIG_FOLDER)
	@echo $(call build_config,test) > $(CONFIG_FILE)
	g++ -g -I. test.cpp -o test -DSKIPTIME=$(SKIPTIME)
	clear && echo "Running all tests:" && ./test --output=color
	

.PHONY: force_test
force_test:
	@rm -rf $(CONFIG_FOLDER)
	@mkdir $(CONFIG_FOLDER)
	@echo $(call build_config,test) > $(CONFIG_FILE)
	g++ -g -I. test.cpp -o test
	clear && echo "Running all tests:" && ./test --output=color
	

.PHONY: pull
pull:
ifeq ($(shell git rev-parse --is-inside-work-tree 2>/dev/null),true)
	@git reset --hard
	@git clean -fdx
	@git pull --ff-only
else
	@echo "No git repository found in the current directory"
endif

clean:
	rm -f app
	rm -f test