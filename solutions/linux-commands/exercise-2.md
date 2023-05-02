- Create a new directory called "lab_exercises" in your home directory

```
mkdir ~/lab_exercises
```

- Inside the "lab_exercises" directory, create a new file called "file1.txt" and write some text in it

```
echo "This is some text for file1" > ~/lab_exercises/file1.txt
```

- Create a copy of "file1.txt" and name it "file2.txt" using the cp command

```
cp ~/lab_exercises/file1.txt ~/lab_exercises/file2.txt
```

- Verify that "file2.txt" is an exact copy of "file1.txt" by opening both files and comparing their contents

```
diff ~/lab_exercises/file1.txt ~/lab_exercises/file2.txt
```

- Create a new directory called "backup" inside the "lab_exercises" directory
  ```
  mkdir ~/lab_exercises/backup
  ```

```
- Move "file1.txt" and "file2.txt" to the "backup" directory using the mv command
```

mv ~/lab_exercises/file1.txt ~/lab_exercises/file2.txt ~/lab_exercises/backup/

```
- Verify that both files have been moved to the "backup" directory by listing its contents
```

ls ~/lab_exercises/backup/

```
- Create a new file called "file3.txt" in the "lab_exercises" directory and write some text in it
```

echo "This is some text for file3" > ~/lab_exercises/file3.txt

```
- Create a new directory called "archive" inside the "lab_exercises" directory
```

mkdir ~/lab_exercises/archive

```
- Move "file3.txt" to the "archive" directory and rename it to "file3_backup.txt" using the mv command
```

mv ~/lab_exercises/file3.txt ~/lab_exercises/archive/file3_backup.txt

```
- Verify that "file3_backup.txt" has been moved to the "archive" directory and that its contents are the same as "file3.txt"
```

diff ~/lab_exercises/archive/file3_backup.txt ~/lab_exercises/file3.txt

```
- Create a new directory called "temp" inside the "lab_exercises" directory
```

mkdir ~/lab_exercises/temp

```
- Create a new file called "file4.txt" in the "temp" directory and write some text in it
```

echo "This is some text for file4" > ~/lab_exercises/temp/file4.txt

```
- Move "file4.txt" to the "lab_exercises" directory using the mv command
```

mv ~/lab_exercises/temp/file4.txt ~/lab_exercises/

```
- Verify that "file4.txt" has been moved to the "lab_exercises" directory and that its contents are the same as before
```

diff ~/lab_exercises/temp/file4.txt ~/lab_exercises/file4.txt

```

```
