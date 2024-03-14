rm -rf result.txt
rm -rf main
g++ -o main *.cpp *.h
cat testSub.txt | ./main

if [ -f "result.txt" ]; then
  HORZ_CHECK=$(diff -b -B result.txt golden/solSub.txt)
  if [ "$HORZ_CHECK" !=  "" ]; then
    echo "Sub - FAIL"
  else
    echo "Sub - PASS"
  fi 
else
  echo "Sub - FAIL (MISSING FILE)"
fi
