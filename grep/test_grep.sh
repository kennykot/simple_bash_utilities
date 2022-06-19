echo "Separate flags";
./s21_grep a aboba.txt > s21_grep.txt
grep a aboba.txt > testing.txt
diff -s s21_grep.txt testing.txt

./s21_grep -i a aboba.txt > s21_grep.txt
grep -i a aboba.txt > testing.txt
diff -s s21_grep.txt testing.txt

./s21_grep -e a aboba.txt > s21_grep.txt
grep -e a aboba.txt > testing.txt
diff -s s21_grep.txt testing.txt

./s21_grep -v a aboba.txt > s21_grep.txt
grep -v a aboba.txt > testing.txt
diff -s s21_grep.txt testing.txt

./s21_grep -n a aboba.txt > s21_grep.txt
grep -n a aboba.txt > testing.txt
diff -s s21_grep.txt testing.txt

./s21_grep -c a aboba.txt > s21_grep.txt
grep -c a aboba.txt > testing.txt
diff -s s21_grep.txt testing.txt

./s21_grep -c -l -n aboba.txt bytes.txt file.txt file2.txt file3.txt > s21_grep.txt
grep -c -l -n aboba.txt bytes.txt file.txt file2.txt file3.txt > testing.txt
diff -s s21_grep.txt testing.txt
