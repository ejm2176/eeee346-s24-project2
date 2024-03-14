rm -rf result.txt
rm -rf main
g++ -o main *.cpp *.h
cat testMul.txt | ./main

if [ -f "result.txt" ]; then
  HORZ_CHECK=$(diff -b -B result.txt golden/solMul.txt)
  if [ "$HORZ_CHECK" !=  "" ]; then
    echo "Mul - FAIL"
  else
    echo "Mul - PASS"
  fi 
else
  echo "Mul - FAIL (MISSING FILE)"
fi
