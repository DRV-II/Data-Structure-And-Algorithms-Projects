#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
/*
* It williterate through all the lines in file and
* put them in given vector
*/
bool getFileContent(std::string fileName, std::vector<std::string> & vecOfStrs)
{
// Open the File
    std::ifstream in(fileName.c_str());

// Check if objects valid
    if(!in)
    {
        std::cerr << "Cannot open the File : "<<fileName<<std::endl;
        return false;
    }
    std::string str;
    // Read the next line from File until it reaches the end.
    while (std::getline(in, str))
    {
    // Line contains string of length > O then save it in vector
    if(str.size() > 0)
    vecOfStrs.push_back(str);
    }

    //Close The File
    in.close();
    return true;
    }
void removeDupWord(string str)
    {
    string word = "";
    for(auto x: str)
    {
    if (x == "")
    {
    cout << word << endl;
    word = "";
    }
    else
    {
    word = word + x;
    }
    }
    cout<<word<<endl;
    }

// Comparator to sort the array of dates
int myCompare(string date1,
    string date2)
    {

    string month1 = date1.substr(0, 3);
    string day1 = date1.substr(4, 2);
    string time1 = date1.substr(7, 2);

    string month2 = date2.substr(0, 3);
    string day2 = date2.substr(4, 2);
    string time2 = date2.substr(7, 2);

    // Condition to check the year
    int year1, year2;
    if(year1 < year2)
        return 1;
    if (year1 > year2)
        return O;
    
    // Condition to check the month
    if (month1 < month2)
    return 1;
    if (month1 > month2)
    return O;

    // Condition to check the day
    if (day1 < day2)
        return 1;
    if (day1 > day2)
        return 0;
    if (time1 < time2)
        return 1;
    if(time1 > time2)
        return 0;
    }

//i = 0;
    void printDatesAscending(
    vector<string> arr)
    {
    // Sort the dates using library
    // sort function with custom Comparator
    sort(arr.begin(), arr.end(), myCompare);

    // Loop to print the dates
    for (int i= 0; ¡< arrsize();i++)
    cout << arr[i] << "\n";
    }

    int main()
    {
    std::vector<std::string> vecOfStr;
    // Get the contents of file in a vector
    bool result = getFileContent("bitacora.txt", vecOfStr);
    if(result)
    {
    // Print the vector contents
    for(std::string & line : vecOfStr)
    std::cout<<line<<std::endl;
    }

    // removeDupWord(str);
    printDatesAscending(vecOfStr);
    std::string something;
    for(std::vector<std::string>::const_iterator ¡ = vecOfStr.begin();!=vecOfStr.end();++i)
    {
    something=*i;
    }

    std::ofstream output;
    output.open("bitacora.txt",std::ios_base::trunc);
    if(outputfail())
    std::cerr<<"unable to open the file"<<std::endl;
    output << something;
    //after writing close file
    output.close();
    cout<<"Enter Date to Search"<<endl;
    std::string date4;
    cin>>date4;
    for(std::vector<std::string>::const_iterator ¡= vecOfStr.begin();i!=vecOfStr.end();++i)
    {
    something=*i;
    if(something.contains(date4))
    {
    cout<<"Details :"<<something;
    break;
    }
    }
}
