# // reading a string
# // using via user input
s=$1
# // getting the length of given string
# s="Hello World"
strlen=${#s}
# // looping for reversing a string
# // initialize i=len-1 for reversing a string and run till i=0
# // printing in the reverse order of the given string
for (( i=$strlen-1; i>=0; i-- ));
do
#  // "${string:$i:1}"extract single character from string
    revstr=$revstr${s:$i:1}
done
echo "Original String : $s"
echo "Reversed String : $revstr"
