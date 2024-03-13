# UCM Makefile for C++ projects
# Angelo Kyrilov

WORKDIR = $(shell pwd)

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

all:
	g++ main.cpp -g -I. -lpthread -o app
	@rm -rf $(CONFIG_FOLDER)
	@mkdir $(CONFIG_FOLDER)
	@echo $(call build_config,app) > $(CONFIG_FILE)

.PHONY: test
test:
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