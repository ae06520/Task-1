#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;
///problem 1:
///Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
bool Problem1(int a[],int n,int c[],int target)
{
    ///the size of array c is 2
    ///that nested because the two number is not always adjacent

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
          if(a[i]+a[j]==target)
          {
              c[0]=i;
              c[1]=j;
              return true;
              break;

          }
        }
    }
    return false;

}
///problem 2:( test if the number is palindrome or No)
int Reverse(int x)
{
    ///that indicate the reverse of the number
    int r=0;
    while(x>0)
    {
        r*=10;
        r+=x%10;
        x/=10;
    }
    return r;
}
string Reverse(string a)
{
    string b=a;
    int s=0,e=a.length()-1;
    while(s<e)
    {
        swap(b[s],b[e]);
        s++;
        e--;
    }
    return b;
}
bool problem2(int x)
{
   if(Reverse(x)==x)return true;
   return false;
}
///problem 3: Add two binary number:
string problem3(string a,string b)
{
string c;
int carry=0;
int n=a.length();
int i=0;
int j=0;
int m=b.length();
while(i<=n-1&&j<=m-1)
{
if(carry==0)
{
if(a[i]=='0'&&b[j]=='0')
{
c+='0';
carry=0;
i++;
j++;
}
else if(a[i]=='1'&&b[j]=='0')
{
c+='1';
carry=0;
i++;
j++;
}
else if(a[i]=='0'&&b[j]=='1')
{
c+='1';
carry=0;
i++;
j++;
}
else if(a[i]=='1'&&b[j]=='1')
{
c+='0';
i++;
j++;
carry=1;
}
}
else if(carry==1)
{
    if(a[i]=='0'&&b[j]=='0')
    {
        c+='1';
        i++;
        j++;
        carry=0;
    }
else if(a[i]=='0'&&b[j]=='1')
    {
        c+='0';
        i++;
        j++;
        carry=1;
    }
else if(a[i]=='1'&&b[j]=='0')
    {
        c+='0';
        i++;
        j++;
        carry=1;
    }
    else if(a[i]=='1'&&b[j]=='1')
    {
        c+='1';
        i++;
        j++;
        carry=1;
    }
}
    }
    while(i<=n-1)
    {
        if(carry==0)
        {
        c+=a[i];
        carry=0;
        i++;
        }
        else if(carry ==1)
        {
            if(a[i]=='0')
            {
                c+='1';
                carry=0;
                i++;
            }
            else if(a[i]=='1')
            {
             c+='0';
             carry= 1;
            i++;
            }

        }
    }
   while(j<=m-1)
    {

        if(carry==0)
        {
        c+=b[j];
        carry=0;
        j++;
        }
        else if(carry==1)
        {
            if(b[j]=='0')
            {
                c+='1';
                carry=0;
                j++;
            }
            else if(b[j]=='1')
            {
             c+='0';
             carry=1;
             j++;
            }

        }
    }
    if(carry==1)c+='1';

    return Reverse(c);
}
///problem 4:single number
int Problem4(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        bool found=false;
        for(int j=0;j<n;j++)
        {
            if(a[i]==a[j]&&i!=j)found=true;
        }
        if(found==false)
        {
            return a[i];
        }
    }
    return -1;
    ///also can be solved by array of occurrence and traverse it {O(n)}
}
///problem 5: Contains Duplicate
void problem5(int arr[],int n)
{
     bool found=false;
       for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i]==arr[j]&&i!=j)found=true;
        }
    }
    if(found==true)cout<<"true"<<endl;
    else cout<<"false"<<endl;
}
///problem 6: base-7
char intTochar(int no)
{
    if(no==0)return('0');
    else if(no==1)return('1');
    else if(no==2)return('2');
    else if(no==3)return('3');
    else if(no==4)return('4');
    else if(no==5)return('5');
    else if(no==6)return('6');
}
string problem6(int base10)
{
    string res;
    if(base10<7)
    {
        res+=intTochar(base10);
    }
    else
    {
    while(base10!=0)
    {
        int reminder=base10%7;
      res+=intTochar(reminder);
        base10/=7;
    }
    }
        return Reverse(res);

}
///problem 7:fibonacci-number
int fib(int n)
{
    if(n==1||n==2)return 1;
    else return fib(n-1)+fib(n-2);
}
///problem 8:Reverse Words in a String III
string problem8(string word)
{
   string result;
   string wordrev;
int i=0;
while(i<=word.length())
{
    if(word[i]==' ')
    {
        result+=Reverse(wordrev)+' ';
        wordrev="";
        i++;
    }
    else if(i==word.length())
    {
       result+=Reverse(wordrev);
        wordrev="";
        i++;
    }
    else
    {
        wordrev+=word[i];
        i++;
    }
}
return result;
}
///problem 9:Remove Element
void problem9(int a[],int &n,int value)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==value)
        {
            for(int j=i;j<n;j++)a[i]=a[i+1];
            n--;
        }
    }
}
/// problem 10: Plus one
void problem10(int a[],int &n)
{
    if(a[n-1]<9)a[n-1]++;
    else if(a[n-1]==9)
    {
        a[n-1]=1;
        a[n]=0;
        n++;
    }
}
int main()
{
    while(true)
    {
        int choice;
        cout<<"Main MINU"<<endl;
        cout<<"1 .Problem 1:Two sum       \t"<<"2 .Problem 2:palindrome number"<<endl;
        cout<<"3 .Problem 3:Add binary    \t"<<"4 .Problem 4:Single number "<<endl;
        cout<<"5 .Problem 5:duplicate elem\t"<<"6 .Problem 6: base-7"<<endl;
        cout<<"7 .Problem 7:Fib_number    \t"<<"8 .Problem 8: Reverse each word in element"<<endl;
        cout<<"9 .Problem 9:Remove element\t"<<"10.Problem 10:Plus one"<<endl;
        cout<<"11.Exit"<<endl;

        cin>>choice;

if(choice==1)
{
    int n;
   cout<<"Enter the size of array"<<endl;
   cin>>n;
    int a[n];
    cout<<"Enter the array element values"<<endl;
    for(int i=0;i<n;i++)cin>>a[i];
int c[2];
cout<<"Enter the sum "<<endl;
int target;
cin>>target;
if(Problem1(a,n,c,target)==true)cout<<" { "<<c[0]<<" , "<<c[1]<<"}"<<endl;
else cout<<"No two element equal that target"<<endl;
    }
else if(choice==2)
{
    int n;
    cin>>n;
    if(problem2(n)==true)cout<<"true"<<endl;
    else cout<<"false"<<endl;
}
else if(choice==3)
{
string a;
cin>>a;
for(int i=0;i<=a.length();i++)cout<<a[i];

string b;
cin>>b;
cout<<"Thanks"<<endl;
    string c=problem3(a,b);
    cout<<c<<endl;
}
else if(choice==4)
{
int n;
cout<<"Enter the number of array in element "<<endl;
cin>>n;
int arr[n];
cout<<"Enter the array elements"<<endl;
for(int i=0;i<n;i++)cin>>arr[i];
int result=Problem4(arr,n);
if(result!=-1)
cout<<"the single one in that array is"<<result<<endl;
else
{
  cout<<"No single one in that array"<<endl;
}
}
else if(choice==5)
{
   int n;
cout<<"Enter the number of array in element "<<endl;
cin>>n;
int arr[n];
cout<<"Enter the array elements"<<endl;
for(int i=0;i<n;i++)cin>>arr[i];
problem5(arr,n);
}
else if(choice==6)
{
    int number;
    cout<<"Enter the number to find it in base 7(0-6)"<<endl;
    cin>>number;
    if(number>=0)cout<<problem6(number)<<endl;
    else
    {
        cout<<"-"<<problem6(-number)<<endl;
    }
}
else if(choice ==7)
{
int num;
cout<<"Enter the number of term in fibonacci series to find the value of it"<<endl;
cin>>num;
cout<<fib(num)<<endl;
}
else if(choice==8)
{
    cout<<"Enter string to reverse each word in that"<<endl;
    string str;
    cin.ignore();
    getline(cin,str);
    cout<<"The result is"<<endl;
    cout<<problem8(str)<<endl;
}
else if(choice==9)
{
    int n;
    cout<<"Enter the number of array element"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the array element\n";
    for(int i=0;i<n;i++)cin>>arr[i];
    int v;
    cout<<"Enter value to remove all occurance of it from the above entered array"<<endl;
    cin>>v;
    problem9(arr,n,v);
    cout<<"array after removed that elem is\n"<<"{ ";
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<"}"<<endl;
}
else if(choice==10)
{
        int n;
    cout<<"Enter the number of array element"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the array element\n";
    for(int i=0;i<n;i++)cin>>arr[i];
   problem10(arr,n);
    cout<<"array plus one operation i\n"<<"{ ";
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<"}"<<endl;
}
}
return 0;
}
