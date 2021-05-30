# searcher.py

For start run .py with arguments(flags):

example: python3.9 -f text.txt -p /home/admin/Desktop


Flags, you can us:
* -f (--file) filename - search file
    * -f test
    * --file text.txt
* -d (--directory) dir_name - search directory
    * -d dir
    * --directory dir
* s (--search) text(can us regex) - search text
    * -s Hello
    * --search ^Hi
* -p (--path) path - set searching file path(default / )
    * -p /home/admin/Desktop/
    * --path /home/admin/dir1/
    * NOT: -p /home/admin/Desktop (write / on end)
* -i (--include) files - include files for searching
    * -i *.txt
        for more then 1: -i [ *.txt 1.py ] (with spaces)
    * --include [ *.sh *.py ]
* -e (--exclude) files - exclude files for searching) 
    * -e *.txt
        for more then 1: -e [ *.txt 1.py ]
    * --exclude [ *.sh *.py ]

You can us all of flags in 1 running, besides -f and -d.


Thank`s for reading!
