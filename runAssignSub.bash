rm -rf result.txt
rm -rf main
g++ -o main *.cpp *.h
cat testAssignSub.txt | ./main

if [ -f "result.txt" ]; then
  HORZ_CHECK=$(diff -b -B result.txt golden/solAssignSub.txt)
  if [ "$HORZ_CHECK" !=  "" ]; then
    echo "AssignSub - FAIL"
  else
    echo "AssignSub - PASS"
  fi 
else
  echo "AssignSub - FAIL (MISSING FILE)"
fi
