#!/bin/bash

valgrind --leak-check=full --show-leak-kinds=all ./so_long "map1.berr"
