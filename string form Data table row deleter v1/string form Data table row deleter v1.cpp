// string form Data table row deleter v1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iterator>
#include <vector>

int main()
{
    // This is our given data. Rows containing "NULL" are not acceptable.
        std::cout << std::endl; std::cout << "Table 1 below contains info about individuals, we want to remove individual with \"NULL\" entries\n\n";
        std::string tableString { "IDnumber,sex,name,location,job\n1,male,jhon,NULL,mechanic\n2,male,kevin,sweden,master\n3,female,katrine,denmark,student\n4,female,Lisa,NULL,NULL\n" };
        std::cout << ">Table 1: The table contains info about individuals. The first row contains the data lables\n____________________\n"; std::cout << tableString; std::cout << "____________________\n";

    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    /* Strategy Summary
    * > dissasemble the string into a vector of strings with each row terminated by "\n"
    * > remove the bad row strings containing NULL
    * > reassemble the strings into one string
    */

    // Here we create the vector to hold each rows as a string
        int lastNewlinePos{ NULL };
        int rowCount{ 0 };
        while (lastNewlinePos != -1)
        {
            if (lastNewlinePos == NULL)
            {
                lastNewlinePos = tableString.find("\n");
            }
            else
            {
                lastNewlinePos = tableString.find("\n", lastNewlinePos + 1);
            }

            if (lastNewlinePos != -1)
            {
                rowCount++;
            }
        }
        std::vector<std::string> rowStrings(rowCount);



    // Here we fill the vector of strings with the string for the row, terminated by \n
        int rowNumber{ 0 };
        for (std::string::iterator it = tableString.begin(); it != tableString.end(); it++)
        {
            if (*it == '\n')
            {
                rowStrings[rowNumber].push_back(*it);
                rowNumber++;
            }
            else {
                rowStrings[rowNumber].push_back(*it);
            }
        }

    // Here we identify and remove the row strings containing the secuence "NULL" using string::find. 
    // no "NULL" returns -1
        std::string searchTerm{ "NULL" };
        for (int i{ 0 }; i < (int)rowStrings.size(); i++)
        {
            if (rowStrings[i].find(searchTerm) < rowStrings[i].length() || rowStrings[i].find(searchTerm) > -1)
            {
                rowStrings[i].erase();
            }
        }
    
    // Here we reasemble the table string with the row strings that did not get removed
        tableString.erase();
        for (int i{ 0 }; i < (int)rowStrings.size(); i++)
        {
            for (std::string::iterator it = rowStrings[i].begin(); it != rowStrings[i].end(); it++)
            {
                tableString.push_back(*it);
            }
        }

    
    // We end by some presentation of the result
        std::cout << "\n\nThe table is a contious string; with newline characters, that are creating the rows in this window.\n";
        std::cout << "This string was separeated into a vector of row strings terminated by the newline characters.\n";
        std::cout << "\nAll rows countaining \"NULL\" was the removed, using vector::erase on the vector of row strings, \n";
        std::cout << "to remove all individuals with \"NULL\" entries.\n";
        std::cout << "The the remaining strings was put back together and is shown in table 2 below.\n";
        
        std::cout << "\n>Table 2: The table contains info about individuals without \"NULL\" entries. The first row contains the data lables\n____________________\n"; std::cout << tableString; std::cout << "____________________\n";






    std::cout << "\n\nData table row deleter v1\n\n";
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
