#!/bin/bash

clear;
git status;
git add -A;
git status;
git commit -m "Automatic push";
git push -u origin master;
