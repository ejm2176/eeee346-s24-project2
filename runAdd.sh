rm -rf result.txt
rm -rf main
g++ -o main *.cpp *.h
cat testAdd.txt | ./main

if [ -f "result.txt" ]; then
  HORZ_CHECK=$(diff -b -B result.txt golden/solAdd.txt)
  if [ "$HORZ_CHECK" !=  "" ]; then
    echo "Add - FAIL"
  else
    echo "Add - PASS"
  fi 
else
  echo "Add - FAIL (MISSING FILE)"
fi
