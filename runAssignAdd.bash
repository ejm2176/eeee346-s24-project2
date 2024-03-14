rm -rf result.txt
rm -rf main
g++ -o main *.cpp *.h
cat testAssignAdd.txt | ./main

if [ -f "result.txt" ]; then
  HORZ_CHECK=$(diff -b -B result.txt golden/solAssignAdd.txt)
  if [ "$HORZ_CHECK" !=  "" ]; then
    echo "AssignAdd - FAIL"
  else
    echo "AssignAdd - PASS"
  fi 
else
  echo "AssignAdd - FAIL (MISSING FILE)"
fi
