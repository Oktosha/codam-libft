#!/bin/bash
shopt -s extglob dotglob;

cd ../libft-00;
rm -rf !(.git)

cd ../codam-libft;
for file in $(git ls-tree -r HEAD --name-only task);
	do cp $file ../libft-00;
done;

cd ../libft-00;
git add .;
git commit -m "$1";
git push;
