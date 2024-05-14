#include "HashTable.h"
#include "TennisWinners.h"
#include "LinearProbing.h"
#include "NonLinearProbing.h"
#include "SeparateChaining.h"
#include "SeparateChaining2.h"
#include "NonLinearProbing2.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

unsigned long hornerHash(string key, unsigned long tableSize) {
    unsigned long hashVal = 0;
    for (char &letter : key) {
        hashVal = hashVal * 37 + letter;
    }
    return hashVal % tableSize;
}

string getTennisWinnerUnique(TennisWinners tWin) {
    return tWin.getUnique();
}

string getTennisWinnerScore(TennisWinners tWin) {
    return tWin.getScore();
}

int main() {
    // Project 5 Main.cpp file
    // Hash table
    // table sizes for all 5 sets of tables
    const unsigned long TABLE_SIZE = 3790;
    const unsigned long TABLE_SIZE2 = 4500;
    const unsigned long TABLE_SIZE3 = 6151;
    const unsigned long TABLE_SIZE4 = 7523;
    const unsigned long TABLE_SIZE5 = 8211;

    // output file for my reads
    ofstream myfile;

    // Tennis winners data vector
    vector<TennisWinners> tWinners;
    getTennisWinnersFromFile("TennisWins2000.csv", tWinners);


    // Part B
    // first set of sep chaining an non linear probing
    // TODO: place marker for set 1
    SeparateChaining<TennisWinners> tWinSC(TABLE_SIZE, getTennisWinnerUnique);
    NonLinearProbing<TennisWinners> tWinNLP(TABLE_SIZE, getTennisWinnerUnique);

    // opens file and prints the table size and the style of table to make data easier to read
    myfile.open("../TennisWinnersReadsTestFile.csv");
    myfile << TABLE_SIZE << "SepChain,";

    int r;
    // adding the twinners to the separate chaining table
    for(TennisWinners &tWin: tWinners){
        r = 0; // sets the read variable to zero before every insertion
        tWinSC.insert(tWin, &r);
        // out put the read value
        myfile << r << ",";
    }
    myfile << " \n";

    myfile << TABLE_SIZE << "NonLinear,";
    // adding the twinners to the non linear probing table
    for(TennisWinners &tWins: tWinners){
        r = 0;
        tWinNLP.insert(tWins, &r);
        myfile << r << ",";
    }
    myfile << "\n";
    // tWinNLP.printTable();

    // second set of Sepchaingin and non linear probing
    // TODO: place marker for set 2
    SeparateChaining<TennisWinners> tWinSC2(TABLE_SIZE2, getTennisWinnerUnique);
    NonLinearProbing<TennisWinners> tWinNLP2(TABLE_SIZE2, getTennisWinnerUnique);

    myfile << TABLE_SIZE2 << "SepChain,";
    // adding the twinners to the separate chaining table
    for(TennisWinners &tWin: tWinners){
        r = 0; // sets the read variable to zero before every insertion
        tWinSC2.insert(tWin, &r);
        // out put the read value
        myfile << r << ",";
    }
    myfile << " \n";

    myfile << TABLE_SIZE2 << "NonLinear,";
    // adding the twinners to the non linear probing table
    for(TennisWinners &tWins: tWinners){
        r = 0;
        tWinNLP2.insert(tWins, &r);
        myfile << r << ",";
    }
    myfile << "\n";

    // third set of Sepchaining and non linear probing
    // TODO: place marker for set 3
    SeparateChaining<TennisWinners> tWinSC3(TABLE_SIZE3, getTennisWinnerUnique);
    NonLinearProbing<TennisWinners> tWinNLP3(TABLE_SIZE3, getTennisWinnerUnique);

    myfile << TABLE_SIZE3 << "SepChain,";
    // adding the twinners to the separate chaining table
    for(TennisWinners &tWin: tWinners){
        r = 0; // sets the read variable to zero before every insertion
        tWinSC3.insert(tWin, &r);
        // out put the read value
        myfile << r << ",";
    }
    myfile << " \n";

    myfile << TABLE_SIZE3 << "NonLinear,";
    // adding the twinners to the non linear probing table
    for(TennisWinners &tWins: tWinners){
        r = 0;
        tWinNLP3.insert(tWins, &r);
        myfile << r << ",";
    }
    myfile << "\n";

    // fourth set of sepchainging and non linear probing
    // TODO: place marker for set 4
    SeparateChaining<TennisWinners> tWinSC4(TABLE_SIZE4, getTennisWinnerUnique);
    NonLinearProbing<TennisWinners> tWinNLP4(TABLE_SIZE4, getTennisWinnerUnique);

    myfile << TABLE_SIZE4 << "SepChain,";
    // adding the twinners to the separate chaining table
    for(TennisWinners &tWin: tWinners){
        r = 0; // sets the read variable to zero before every insertion
        tWinSC4.insert(tWin, &r);
        // out put the read value
        myfile << r << ",";
    }
    myfile << " \n";

    myfile << TABLE_SIZE4 << "NonLinear,";
    // adding the twinners to the non linear probing table
    for(TennisWinners &tWins: tWinners){
        r = 0;
        tWinNLP4.insert(tWins, &r);
        myfile << r << ",";
    }
    myfile << "\n";

    // fifth set of cep chaining and non linear probing
    // TODO: place marker for set 5
    SeparateChaining<TennisWinners> tWinSC5(TABLE_SIZE5, getTennisWinnerUnique);
    NonLinearProbing<TennisWinners> tWinNLP5(TABLE_SIZE5, getTennisWinnerUnique);

    myfile << TABLE_SIZE5 << "SepChain,";
    // adding the twinners to the separate chaining table
    for(TennisWinners &tWin: tWinners){
        r = 0; // sets the read variable to zero before every insertion
        tWinSC5.insert(tWin, &r);
        // out put the read value
        myfile << r << ",";
    }
    myfile << " \n";

    myfile << TABLE_SIZE5 << "NonLinear,";
    // adding the twinners to the non linear probing table
    for(TennisWinners &tWins: tWinners){
        r = 0;
        tWinNLP5.insert(tWins, &r);
        myfile << r << ",";
    }
    myfile << "\n";

    // TODO: Part C
    // using TABLE_SIZE4 because in my data it was best of all them

    // normal key with different hash function
    SeparateChaining2<TennisWinners> tWinSC6(TABLE_SIZE4, getTennisWinnerUnique);
    NonLinearProbing2<TennisWinners> tWinNLP6(TABLE_SIZE4, getTennisWinnerUnique);

    myfile << TABLE_SIZE4 << " Sep chainging different hash but normal key,";
    for(TennisWinners &tWin: tWinners){
        r = 0;
        tWinSC6.insert(tWin, &r);
        myfile << r << ",";
    }
    myfile << "\n";

    myfile << TABLE_SIZE4 << " Non linear probing different hash but normal key,";
    for(TennisWinners &tWin: tWinners){
        r = 0;
        tWinNLP6.insert(tWin, &r);
        myfile << r << ",";
    }
    myfile << "\n";

    // different key with normal hash function
    SeparateChaining<TennisWinners> tWinSC7(TABLE_SIZE4, getTennisWinnerScore);
    NonLinearProbing<TennisWinners> tWinNLP7(TABLE_SIZE4, getTennisWinnerScore);

    myfile << TABLE_SIZE4 << " Sep chaining normal hash different key,";
    for(TennisWinners &tWin: tWinners){
        r = 0;
        tWinSC7.insert(tWin, &r);
        myfile << r << ",";
    }
    myfile << "\n";
    tWinSC7.printTable();

    myfile << TABLE_SIZE4 << " Non linear probing normal hash different key,";
    for(TennisWinners &tWin: tWinners){
        r = 0;
        tWinNLP7.insert(tWin, &r);
        myfile << r << ",";
    }
    myfile << "\n";

    // both different key and hash function
    SeparateChaining2<TennisWinners> tWinSC8(TABLE_SIZE4, getTennisWinnerScore);
    NonLinearProbing2<TennisWinners> tWinNLP8(TABLE_SIZE4, getTennisWinnerScore);

    myfile << TABLE_SIZE4 << " Sep chaining differnt hash and key,";
    for(TennisWinners &tWin: tWinners){
        r = 0;
        tWinSC8.insert(tWin, &r);
        myfile << r << ",";
    }
    myfile << "\n";

    myfile << TABLE_SIZE4 << " Non Linear Probing different hash and key,";
    for(TennisWinners &tWin: tWinners){
        r = 0;
        tWinNLP8.insert(tWin, &r);
        myfile << r << ",";
    }
    myfile << "\n";

    // closing my file
    myfile.close();

    // returning 0 means there were no errors in the run any other number means error
    return 0;
}
