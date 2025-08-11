#!/bin/sh

find . -type f,d -iname "*.sh" -exec basename {} .sh ';'

