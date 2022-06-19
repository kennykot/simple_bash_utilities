echo "Separate flags";
./s21_cat -b bytes.txt > s21_cat.txt
cat -b bytes.txt > testing.txt
diff -s s21_cat.txt testing.txt

./s21_cat -v bytes.txt > s21_cat.txt
cat -v bytes.txt > testing.txt
diff -s s21_cat.txt testing.txt

./s21_cat -e bytes.txt > s21_cat.txt
cat -e bytes.txt > testing.txt
diff -s s21_cat.txt testing.txt

./s21_cat -n bytes.txt > s21_cat.txt
cat -n bytes.txt > testing.txt
diff -s s21_cat.txt testing.txt

./s21_cat -s bytes.txt > s21_cat.txt
cat -s bytes.txt > testing.txt
diff -s s21_cat.txt testing.txt

./s21_cat -t bytes.txt > s21_cat.txt
cat -t bytes.txt > testing.txt
diff -s s21_cat.txt testing.txt

./s21_cat bytes.txt > s21_cat.txt
cat bytes.txt > testing.txt
diff -s s21_cat.txt testing.txt

echo "Combinate flags";
./s21_cat -s -e bytes.txt > s21_cat.txt
cat -s -e bytes.txt > testing.txt
diff -s s21_cat.txt testing.txt

./s21_cat -b -t bytes.txt > s21_cat.txt
cat -b -t bytes.txt > testing.txt
diff -s s21_cat.txt testing.txt

./s21_cat -e -n bytes.txt > s21_cat.txt
cat -e -n bytes.txt > testing.txt
diff -s s21_cat.txt testing.txt

./s21_cat -t -n bytes.txt > s21_cat.txt
cat -t -n bytes.txt > testing.txt
diff -s s21_cat.txt testing.txt

./s21_cat -s -t bytes.txt > s21_cat.txt
cat -s -t bytes.txt > testing.txt
diff -s s21_cat.txt testing.txt

./s21_cat -n -e bytes.txt > s21_cat.txt
cat -n -e bytes.txt > testing.txt
diff -s s21_cat.txt testing.txt

./s21_cat -n -b bytes.txt > s21_cat.txt
cat -n -b bytes.txt > testing.txt
diff -s s21_cat.txt testing.txt

./s21_cat -s -e -t bytes.txt > s21_cat.txt
cat -s -e -t bytes.txt > testing.txt
diff -s s21_cat.txt testing.txt

./s21_cat -n -b -s -t -e -v bytes.txt > s21_cat.txt
cat -n -b -s -t -e bytes.txt > testing.txt
diff -s s21_cat.txt testing.txt
