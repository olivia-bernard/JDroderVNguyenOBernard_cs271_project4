#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "usecase.cpp"
#include "bst.cpp"


using namespace std;

void test_empty() 
{
    try
    {
        BST<string, int> bst;
        if(!bst.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }
        bst.insert("one",1);
        if(bst.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }

        BST<string, string> str_str;
        if(!str_str.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }
        str_str.insert("hi", "there");
        if(str_str.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }

        BST<int, string> int_str;
        if(!int_str.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }
        int_str.insert(34, "thirtyfour");
        if(int_str.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }

        BST<int, int> int_int;
        if(!int_int.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }
        int_int.insert(9203, 48);
        if(int_int.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }

        BST<int, float> int_fl;
        if(!int_fl.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }
        int_fl.insert(124, 43928.1);
        if(int_fl.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }

        BST<float, float> fl_fl;
        if(!fl_fl.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }
        fl_fl.insert(1325.4, 0.1);
        if(fl_fl.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }

        BST<float, int> fl_int;
        if(!fl_int.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }
        fl_int.insert(9.4, 0);
        if(fl_int.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }

        BST<float, string> fl_str;
        if(!fl_str.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }
        fl_str.insert(100.4, "gosh");
        if(fl_str.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }

        BST<string, float> str_fl;
        if(!str_fl.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }
        str_fl.insert("golly", 325.6);
        if(str_fl.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }

        //

        str_fl.remove(325.6);
        if(!str_fl.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }
        fl_str.remove("gosh");
        if(!fl_str.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }
        fl_int.remove(0)
        if(!fl_int.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }
        fl_fl.remove(0.1);
        if(!fl_fl.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }
        int_fl.remove(43928.1);
        if(!int_fl.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }
        int_int.remove(48);
        if(!int_int.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }
        int_str.remove("thirtyfour");
        if(!int_str.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }
        str_str.remove("there");
        if(!str_str.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }
        bst.remove(1);
        if(!bst.empty()) 
        {
            cout << "Incorrect empty result." << endl;
        }
    }
    catch(exception& e)
    {
        cerr << "Error in determining if BST is empty : " << e.what() << endl;
    }
}

void test_insert() 
{
    try {
        BST<string, int> bst;
        bst.insert("one", 1);
        string bst_str = bst.to_string();
        if(bst_str != "1") 
        {
            cout << "Incorrect result of inserting (\"one\", 1). Expected 1 but got : " << bst_str << endl;
        }
        for(int i = 2; i <= 10; i++) 
        {
            bst.insert("some data", i);
        }
        bst_str = bst.to_string();
        if(bst_str != "1 2 3 4 5 6 7 8 9 10") 
        {
            cout << "Incorrect result of inserting keys 1-10 in order. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }

        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) 
        {
            balanced_bst.insert("some data", vals[i]);
        }
        bst_str = balanced_bst.to_string();
        if(bst_str != "5 2 7 1 3 6 9 4 8 10") {
            cout << "Incorrect result of inserting keys {5, 2, 7, 1, 3, 4, 6, 9, 8, 10}. Expected 5 2 7 1 3 6 9 4 8 10 but got : " << bst_str << endl;
        }

        BST<int, int> negatives;
        int negs[5] = {5, -10, -8, 10, 20};
        for(int i=0; i<5; i++)
        {
            negatives.insert(-15, negs[i]);
        }
        bst_str = negatives.to_string();
        if(bst_str != "5 -10 10 -8 20") {
            cout << "Incorrect result of inserting keys {5, -10, -8, 10, 20}. Expected 5 -10 10 -8 20 but got : " << bst_str << endl;
        }

        BST<int, int> wonky;
        int vals2[9] = {50, 25, 24, 10, 9, 80, 90, 500, 1000};
        for(int i = 0; i < 9; i++) 
        {
            wonky.insert(0, vals2[i]);
        }
        bst_str = wonky.to_string();
        if(bst_str != "50 25 80 24 90 10 500 9 1000") {
            cout << "Incorrect result of inserting keys {50, 25, 24, 10, 9, 80, 90, 500, 1000}. Expected 50 25 80 24 90 10 500 9 1000 but got : " << bst_str << endl;
        }

        BST<string, string> unbalanced_str;
        string strs[5] = {"a", "b", "c", "d", "e"};
        for(int i = 0; i < 5; i++) 
        {
            unbalanced_str.insert("blah", strs[i]);
        }
        bst_str = unbalanced_str.to_string();
        if(bst_str != "a b c d e") {
            cout << "Incorrect result of inserting keys {a b c d e}. Expected a b c d e but got : " << bst_str << endl;
        }

        BST<string, string> screaming;
        string scream[7] = {"aa", "aaaa", "aaaaaa", "aaa", "aaaaaaaaaa", "a", "b"};
        for(int i = 0; i < 7; i++) 
        {
            screaming.insert("a scream", scream[i]);
        }
        bst_str = screaming.to_string();
        if(bst_str != "aa a aaaa aaa aaaaaa aaaaaaaaaa b") {
            cout << "Incorrect result of inserting keys {aa aaaa aaaaaa aaa aaaaaaaaaa a b}. Expected aa a aaaa aaa aaaaaa aaaaaaaaaa b but got : " << bst_str << endl;
        }

        BST<float, string> campus;
        string buildings[5] = {"burton morgan", "barney davis", "fellows", "olin", "eisner"};
        for(int i = 0; i < 5; i++) 
        {
            campus.insert(10900.0, buildings[i]);
        }
        bst_str = campus.to_string();
        if(bst_str != "burton morgan barney davis fellows eisner olin") {
            cout << "Incorrect result of inserting keys {burton morgan barney davis fellows olin eisner}. Expected burton morgan barney davis fellows eisner olin but got : " << bst_str << endl;
        }

        BST<int, string> mixed;
        string misc[6] = {"?", "confusion", ":..", "@", "/boogie", " "};
        for(int i = 0; i < 6; i++) 
        {
            mixed.insert(10, misc[i]);
        }
        bst_str = misc.to_string();
        if(bst_str != "? :.. confusion /boogie @  ") {
            cout << "Incorrect result of inserting keys {? confusion :.. @ /boogie  }. Expected ? :.. confusion /boogie @   but got : " << bst_str << endl;
        }

        BST<string, int> big_nums;
        int biggies[5] = {900000, 49920, 100335, 4902304, 3190855};
        for(int i = 0; i < 5; i++) 
        {
            mixed.insert("wow big", biggies[i]);
        }
        bst_str = biggies.to_string();
        if(bst_str != "900000 49920 4902304 100335 3190855") {
            cout << "Incorrect result of inserting keys {900000, 49920, 100335, 4902304, 3190855}. Expected 900000 49920 4902304 100335 3190855 but got : " << bst_str << endl;
        }

        BST<string, float> fl_bst;
        float fl_arr[7] = {10.4, 10.5, 9.4, 100.9, 100.1, 5.1, 0.1};
        for(int i = 0; i < 7; i++) 
        {
            fl_bst.insert("balloooooons", fl_arr[i]);
        }
        bst_str = fl_bst.to_string();
        if(bst_str != "10.4 9.4 10.5 5.1 100.9 0.1 100.1") {
            cout << "Incorrect result of inserting keys {10.4, 10.5, 9.4, 100.9, 100.1, 5.1, 0.1}. Expected 10.4 9.4 10.5 5.1 100.9 0.1 100.1 but got : " << bst_str << endl;
        }

        BST<float, string> halloween;
        string spooky[5] = {"mummy", "vampire", "ghost", "witch", "pumpkin"};
        for(int i = 0; i < 5; i++) 
        {
            halloween.insert(666.6, spooky[i]);
        }
        bst_str = halloween.to_string();
        if(bst_str != "mummy ghost vampire pumpkin witch") {
            cout << "Incorrect result of inserting keys {mummy vampire ghost witch pumpkin}. Expected mummy ghost vampire pumpkin witch but got : " << bst_str << endl;
        }

    } catch(exception& e) {
        cerr << "Error inserting into bst : " << e.what() << endl;
    }
}

void test_get() 
{
    try {
        string val;
        float fl;
        int num;

        BST<string, int> bst_1;
        val = bst_1.get(0);
        if(val!="") {
            cout << "Incorrect get result from empty bst. Expected 0 but got " << val << endl;
        }
        BST<string, string> bst_2;
        val = bst_2.get("nope");
        if(val!="") {
            cout << "Incorrect get result from empty bst. Expected 0 but got " << val << endl;
        }
        BST<string, float> bst_3;
        val = bst_3.get(0.0);
        if(val!="") {
            cout << "Incorrect get result from empty bst. Expected 0 but got " << val << endl;
        }
        BST<int, string> bst_4;
        num = bst_4.get("nope");
        if(num!="") {
            cout << "Incorrect get result from empty bst. Expected 0 but got " << num << endl;
        }
        BST<int, float> bst_5;
        num = bst_5.get(0.0);
        if(num!="") {
            cout << "Incorrect get result from empty bst. Expected 0 but got " << num << endl;
        }
        BST<int, int> bst_6;
        num = bst_6.get(0);
        if(num!="") {
            cout << "Incorrect get result from empty bst. Expected 0 but got " << num << endl;
        }
        BST<float, string> bst_7;
        fl = bst_7.get("nope");
        if(fl!="") {
            cout << "Incorrect get result from empty bst. Expected 0 but got " << fl << endl;
        }
        BST<float, int> bst_8;
        fl = bst_8.get(0);
        if(fl!="") {
            cout << "Incorrect get result from empty bst. Expected 0 but got " << fl << endl;
        }
        BST<float, float> bst_9;
        fl = bst_9.get(0.0);
        if(fl!="") {
            cout << "Incorrect get result from empty bst. Expected 0 but got " << fl << endl;
        }

        //
        
        bst_1.insert("one",1);
        val = bst_1.get(1);
        if(val != "one") {
            cout << "Incorrect get result. Expected \"one\" but got : " << val << endl;
        }

        BST<string, string> western;
        western.insert("lone ranger", "tonto");
        western.insert("yee", "haw");
        western.insert("stagecoach", "robbers");
        western.insert("cowboy", "cowgirl");
        val = western.get("haw");
        if(val != "yee") {
            cout << "Incorrect get result. Expected \"yee\" but got : " << val << endl;
        }
        val = western.get("ranch");
        if(val != "") //ranch is not in BST
        {
            cout << "Incorrect get result. Expected \"\" because key is not in BST but got : " << val << endl;
        }

        BST<int, string> numbers;
        numbers.insert(35, "thirtyfive");
        numbers.insert(10, "ten");
        numbers.insert(500, "fivehundred");
        num = numbers.get("ten");
        if(num != 10)
        {
            cout << "Incorrect get result. Expected \"10\" but got : " << num << endl;
        }
        num = numbers.get("eighty");
        if(num != 0) //eighty is not in BST
        {
            cout << "Incorrect get result. Expected \"0\" because key is not in BST but got : " << num << endl;
        }

        BST<float, string> bubbly;
        bubbly.insert(12.5, "sprite");
        bubbly.insert(55.9, "red bull");
        bubbly.insert(10.4, "kombucha");
        bubbly.insert(25.3, "root beer");
        fl = bubbly.get("kombucha");
        if(fl != 10.4)
        {
            cout << "Incorrect get result. Expected \"10.4\" but got : " << fl << endl;
        }
        fl = bubbly.get("sprite");
        if(fl != 12.5)
        {
            cout << "Incorrect get result. Expected \"12.5\" but got : " << fl << endl;
        }
        fl = bubbly.get("mountain dew");
        if(fl != 0) //no mtn dew in bst
        {
            cout << "Incorrect get result. Expected \"0\" because key is not in BST but got : " << fl << endl;
        }

        BST<string, int> numbers2;
        numbers2.insert("fourtyfive", 45);
        numbers2.insert("twenty", 20);
        numbers2.insert("onethousand", 1000);
        val = numbers2.get(20);
        if(val != "twenty") 
        {
            cout << "Incorrect get result. Expected \"twenty\" but got : " << val << endl;
        }
        val = numbers2.get(1001);
        if(val != 0) //no 1001 in bst
        {
            cout << "Incorrect get result. Expected \"0\" because key is not in BST but got : " << val << endl;
        }

        BST<float, int> deci;
        deci.insert(10.9, 10);
        deci.insert(15.5, 15);
        deci.insert(90.1, 90);
        fl = deci.get(10);
        if(fl != 10.9) 
        {
            cout << "Incorrect get result. Expected \"10.9\" but got : " << fl << endl;
        }
        fl = deci.get(19);
        if(fl != 0) //no 19 in bst
        {
            cout << "Incorrect get result. Expected \"0\" because key is not in BST but got : " << fl << endl;
        }

        BST<int, int> ints;
        ints.insert(15, 30);
        ints.insert(50, 100);
        ints.insert(16, 32);
        num = ints.get(32);
        if(num != 16)
        {
            cout << "Incorrect get result. Expected \"q6\" because key is not in BST but got : " << num << endl;
        }
        num = ints.get(50);
        if(num != 0) //no 50 key in bst
        {
            cout << "Incorrect get result. Expected \"0\" because key is not in BST but got : " << num << endl;
        }

        BST<string, float> exams;
        exams.insert("calculus", 78.5);
        exams.insert("philosophy", 99.9);
        exams.insert("zumba", 60.4);
        exams.insert("compsci", 10.2);
        val = exams.get(78.5);
        if(val != "calculus") 
        {
            cout << "Incorrect get result. Expected \"calculus\" but got : " << val << endl;
        }
        val = exams.get(100.0);
        if(val != "") //no 100.0 in bst :(
        {
            cout << "Incorrect get result. Expected \"\" because key is not in BST but got : " << val << endl;
        }

        BST<int, float> point;
        point.insert(1, 1.1);
        point.insert(-1, -1.1);
        point.insert(24, 24.1);
        num = point.get(-1.1);
        if(num != -1)
        {
            cout << "Incorrect get result. Expected \"-1\" but got : " << num << endl;
        }
        num = point.get(10.1);
        if(num != 0) //no 10.1 in bst
        {
            cout << "Incorrect get result. Expected \"0\" because key is not in BST but got : " << fl << endl;
        }

        BST<float, float> too_floaty;
        too_floaty.insert(100.1, 40.8);
        too_floaty.insert(80.5, 1390.0);
        too_floaty.insert(78.3, 1.1);
        fl = too_floaty.get(1.1);
        if(fl != 78.3)
        {
            cout << "Incorrect get result. Expected \"1.1\" because key is not in BST but got : " << fl << endl;
        }
        fl = too_floaty.get(16.6);
        if(fl != 0.0) //no 16.6 in bst
        {
            cout << "Incorrect get result. Expected \"0.0\" because key is not in BST but got : " << fl << endl;
        }
        
    } catch(exception& e) {
        cerr << "Error in getting data from bst : " << e.what() << endl;
    }
}

void test_remove() 
{
    try {
        string bst_str;

        BST<string, int> str_int;
        str_int.remove(0);
        bst_str = str_int.to_string();
        if(bst_str != "") 
        {
            cout << "Incorrect result of removing 0 from empty BST. Expected empty string but got : " << bst_str << endl;
        }
        BST<string, float> str_fl;
        str_fl.remove(-10.5);
        bst_str = str_fl.to_string();
        if(bst_str != "") 
        {
            cout << "Incorrect result of removing -10.5 from empty BST. Expected empty string but got : " << bst_str << endl;
        }
        BST<string, string> str_str;
        str_str.remove("hello");
        bst_str = str_str.to_string();
        if(bst_str != "") 
        {
            cout << "Incorrect result of removing hello from empty BST. Expected empty string but got : " << bst_str << endl;
        }
        BST<int, int> int_int;
        int_int.remove(1);
        bst_str = int_int.to_string();
        if(bst_str != "") 
        {
            cout << "Incorrect result of removing 1 from empty BST. Expected empty string but got : " << bst_str << endl;
        }
        BST<int, float> int_fl;
        int_fl.remove(1555.5);
        bst_str = int_fl.to_string();
        if(bst_str != "") 
        {
            cout << "Incorrect result of removing 1555.5 from empty BST. Expected empty string but got : " << bst_str << endl;
        }
        BST<int, string> int_str;
        int_str.remove("hello");
        bst_str = int_str.to_string();
        if(bst_str != "") 
        {
            cout << "Incorrect result of removing hello from empty BST. Expected empty string but got : " << bst_str << endl;
        }
        BST<float, int> fl_int;
        fl_int.remove(-89);
        bst_str = fl_int.to_string();
        if(bst_str != "") 
        {
            cout << "Incorrect result of removing -89 from empty BST. Expected empty string but got : " << bst_str << endl;
        }
        BST<float, float> fl_fl;
        fl_fl.remove(9.0);
        bst_str = fl_fl.to_string();
        if(bst_str != "") 
        {
            cout << "Incorrect result of removing 9.0 from empty BST. Expected empty string but got : " << bst_str << endl;
        }
        BST<float, string> fl_str;
        fl_str.remove("hello");
        bst_str = fl_str.to_string();
        if(bst_str != "") 
        {
            cout << "Incorrect result of removing hello from empty BST. Expected empty string but got : " << bst_str << endl;
        }

        //

        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) 
        {
            balanced_bst.insert("some data", vals[i]);
        }
        balanced_bst.remove(7);
        bst_str = balanced_bst.to_string();
        if(bst_str != "5 2 8 1 3 6 9 4 10") {
            cout << "Incorrect result of removing 7. Expected 5 2 8 1 3 6 9 4 10 but got : " << bst_str << endl;
        }

        BST<string, int> unbalanced;
        int unbal[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for (int i=0; i<10; i++)
        {
            unbalanced.insert("kooky", unbal[i]);
        }
        unbalanced.remove(10);
        bst_str = unbalanced.to_string();
        if(bst_str != "1 2 3 4 5 6 7 8 9") 
        {
            cout << "Incorrect result of removing 10. Expected 1 2 3 4 5 6 7 8 9 but got : " << bst_str << endl;
        }
        unbalanced.remove(6);
        unbalanced.remove(3);
        bst_str = unbalanced.to_string();
        if(bst_str != "1 2 4 5 7 8 9") 
        {
            cout << "Incorrect result of removing 6 and 3. Expected 1 2 4 5 7 8 9 but got : " << bst_str << endl;
        }

        BST<int, int> emptied;
        emptied.insert(5, 10);
        emptied.insert(-5, -10);
        emptied.remove(10);
        bst_str = emptied.to_string();
        if(bst_str != "-10") 
        {
            cout << "Incorrect result of removing 10. Expected -10 but got : " << bst_str << endl;
        }
        emptied.remove(-5);
        bst_str = emptied.to_string();
        if(bst_str != "-10") 
        {
            cout << "Incorrect result of removing a non-key. Expected -10 but got : " << bst_str << endl;
        }
        emptied.remove(-10);
        bst_str = emptied.to_string();
        if(bst_str != "") 
        {
            cout << "Incorrect result of removing -10. Expected nothing but got : " << bst_str << endl;
        }
        emptied.remove(0);
        bst_str = emptied.to_string();
        if(bst_str != "") 
        {
            cout << "Incorrect result of removing from empty BST. Expected nothing but got : " << bst_str << endl;
        }

        BST<string, string> body;
        string bod[5] = {"brain", "liver", "lungs", "aorta", "heart"};
        for (int i=0; i<5; i++)
        {
            body.insert("meat parts", bod[i]);
        }
        body.remove("liver");
        bst_str = body.to_string();
        if(bst_str != "brain aorta lungs heart") 
        {
            cout << "Incorrect result of removing liver from BST. Expected brain aorta lungs heart but got : " << bst_str << endl;
        }
        body.remove("brain");
        bst_str = body.to_string();
        if(bst_str != "heart aorta lungs") 
        {
            cout << "Incorrect result of removing brain from BST. Expected heart aorta lungs but got : " << bst_str << endl;
        }
        body.remove("stomach");
        bst_str = body.to_string();
        if(bst_str != "heart aorta lungs") 
        {
            cout << "Incorrect result of removing non-key from BST. Expected nothing but got : " << bst_str << endl;
        }

        BST<string, float> height;
        height.insert("sally", 4.8);
        height.insert("zoe", 5.5);
        height.insert("bobby", 6.2);
        height.insert("alice", 6.1);
        height.insert("tony", 4.4);
        height.remove(6.2);
        bst_str = height.to_string();
        if(bst_str != "4.8 4.4 5.5 6.1") 
        {
            cout << "Incorrect result of removing 6.2 from BST. Expected 4.8 4.4 5.5 6.1 but got : " << bst_str << endl;
        }

        BST<int, int> nums;
        int numbas[7] = {4, 2, 8, 6, 5, 10, 7};
        for (int i=0; i<7; i++)
        {
            nums.insert(-100, numbas[i]);
        }
        nums.remove(6);
        bst_str = nums.to_string();
        if(bst_str != "4 2 8 7 10 5") 
        {
            cout << "Incorrect result of removing 6 from BST. Expected 4 2 8 7 10 5 but got : " << bst_str << endl;
        }
        nums.remove(4);
        if(bst_str != "8 2 7 5 10") 
        {
            cout << "Incorrect result of removing 4 from BST. Expected 8 2 7 5 10 but got : " << bst_str << endl;
        }

        BST<float, int> large;
        int big[5] = {13053, 2390, 19303, 20020};
        for (int i=0; i<5; i++)
        {
            large.insert(5000.5, big[i]);
        }
        large.remove(19303);
        if(bst_str != "13053 2390 20020") 
        {
            cout << "Incorrect result of removing 19303 from BST. Expected 13053 2390 20020 but got : " << bst_str << endl;
        }
        large.remove(2390);
        if(bst_str != "13053 20020") 
        {
            cout << "Incorrect result of removing 2390 from BST. Expected 13053 20020 but got : " << bst_str << endl;
        }

        BST<string, int> n;
        int negativos[6] = {0, -1500, 2350, -90, 500, 8};
        for (int i=0; i<6; i++)
        {
            large.insert("negs", negativos[i]);
        }
        large.remove(0);
        if(bst_str != "2350 -1500 500 -90 8") 
        {
            cout << "Incorrect result of removing 0 from BST. Expected 2350 -1500 500 -90 8 but got : " << bst_str << endl;
        }

    } catch(exception& e) {
        cerr << "Error in removing node from bst : " << e.what() << endl;
    }
}

void test_max_data() 
{
    try {
        string max_str;

        //empties
        BST<string, string> str_str;
        max_str = str_str.max_data();
        if(max_str != "") {
            cout << "Incorrect result finding max_data of empty BST. Expected nothing but got : " << max_str << endl;
        }
        BST<string, float> str_fl;
        max_str = str_fl.max_data();
        if(max_str != "0") {
            cout << "Incorrect result finding max_data of empty BST. Expected 0 but got : " << max_str << endl;
        }
        BST<string, int> str_int;
        max_str = str_int.max_data();
        if(max_str != "0") {
            cout << "Incorrect result finding max_data of empty BST. Expected 0 but got : " << max_str << endl;
        }
        BST<float, string> fl_str;
        max_str = fl_str.max_data();
        if(max_str != "") {
            cout << "Incorrect result finding max_data of empty BST. Expected nothing but got : " << max_str << endl;
        }
        BST<float, float> fl_fl;
        max_str = fl_fl.max_data();
        if(max_str != "0") {
            cout << "Incorrect result finding max_data of empty BST. Expected 0 but got : " << max_str << endl;
        }
        BST<float, int> fl_int;
        max_str = fl_int.max_data();
        if(max_str != "0") {
            cout << "Incorrect result finding max_data of empty BST. Expected 0 but got : " << max_str << endl;
        }
        BST<int, string> int_str;
        max_str = int_str.max_data();
        if(max_str != "") {
            cout << "Incorrect result finding max_data of empty BST. Expected nothing but got : " << max_str << endl;
        }
        BST<int, float> int_float;
        max_str = int_float.max_data();
        if(max_str != "0") {
            cout << "Incorrect result finding max_data of empty BST. Expected 0 but got : " << max_str << endl;
        }
        BST<int, int> int_int;
        max_str = int_int.max_data();
        if(max_str != "0") {
            cout << "Incorrect result finding max_data of empty BST. Expected 0 but got : " << max_str << endl;
        }

        //

        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        max_str = balanced_bst.max_data();
        if(max_str != "10 data") {
            cout << "Incorrect result of max_data. Expected \"10 data\" but got : " << max_str << endl;
        }

        BST<string, int> unbalanced;
        int unb[5] = {0, -1 ,-2, -3, -4};
        for(int i = 0; i < 5; i++) {
            unbalanced.insert(to_string(unb[i]) + " data", unb[i]);
        }
        max_str = unbalanced.max_data();
        if(max_str != "0 data") {
            cout << "Incorrect result of max_data. Expected \"0 data\" but got : " << max_str << endl;
        }

        BST<string, int> pos_unb;
        int unb2[5] = {0, 1, 2, 3, 4};
        for(int i = 0; i < 5; i++) 
        {
            pos_unb.insert(to_string(unb2[i]) + " data", unb2[i]);
        }
        max_str = pos_unb.max_data();
        if(max_str != "4 data") 
        {
            cout << "Incorrect result of max_data. Expected \"4 data\" but got : " << max_str << endl;
        }

        BST<string, string> pride;
        pride.insert("bisexual", "purple");
        pride.insert("gay", "green");
        pride.insert("lesbian", "orange");
        pride.insert("straight", "white");
        max_str = pride.max_data();
        if(max_str != "straight") 
        {
            cout << "Incorrect result of max_data. Expected \"straight\" but got : " << max_str << endl;
        }
        pride.insert("wait, that's not a flag", "zebra");
        max_str = pride.max_data();
        if(max_str != "wait, that's not a flag") 
        {
            cout << "Incorrect result of max_data. Expected \"wait, that's not a flag\" but got : " << max_str << endl;
        }

        BST<int, string> alph;
        alph.insert(6, "F");
        alph.insert(5, "E");
        alph.insert(1, "A");
        alph.insert(10, "J");
        max_str = alph.max_data();
        if(max_str != "10") 
        {
            cout << "Incorrect result of max_data. Expected \"10\" but got : " << max_str << endl;
        }
        alph.remove("J");
        max_str = alph.max_data();
        if(max_str != "6") 
        {
            cout << "Incorrect result of max_data. Expected \"6\" but got : " << max_str << endl;
        }

        BST<int, float> floaty;
        floaty.insert(5, 5.1);
        floaty.insert(200, 0.1);
        floaty.insert(50000, 0.3);
        floaty.insert(0, 15.5);
        max_str = floaty.max_data();
        if(max_str != "0") 
        {
            cout << "Incorrect result of max_data. Expected \"15.5\" but got : " << max_str << endl;
        }

        BST<string, string> punct;
        punct.insert("question mark", "?");
        punct.insert("big A", "A");
        punct.insert("quote", "'");
        punct.insert("little a", "a");
        punct.insert("interrobang", "?!");
        punct.insert("tilde", "~");
        max_str = punct.max_data();
        if(max_str != "tilde") 
        {
            cout << "Incorrect result of max_data. Expected \"tilde\" but got : " << max_str << endl;
        }
        punct.remove("~");
        max_str = punct.max_data();
        if(max_str != "little a") 
        {
            cout << "Incorrect result of max_data. Expected \"little a\" but got : " << max_str << endl;
        }

        BST<float, float> one;
        one.insert(1.1, 13.4);
        max_str = one.max_data();
        if(max_str != "1.1") 
        {
            cout << "Incorrect result of max_data. Expected \"1.1\" but got : " << max_str << endl;
        }
        one.remove(13.4);
        max_str = one.max_data();
        if(max_str != "0") 
        {
            cout << "Incorrect result of max_data of empty BST. Expected 0 but got : " << max_str << endl;
        }


    } catch(exception& e) {
        cerr << "Error in determining data of max node in bst : " << e.what() << endl;
    }
}

void test_max_key() 
{
    try {
        int max_k;

        //empties
        BST<string, string> ss;
        min_k = ss.min_key() ;
        if(min_k != 0) {
            cout << "Incorrect result of min_key of empty BST. Expected 0 but got : " << min_k << endl;
        }
        BST<string, int> si;
        min_k = si.min_key() ;
        if(min_k != 0) {
            cout << "Incorrect result of min_key of empty BST. Expected 0 but got : " << min_k << endl;
        }
        BST<string, float> sf;
        min_k = sf.min_key() ;
        if(min_k != 0) {
            cout << "Incorrect result of min_key of empty BST. Expected 0 but got : " << min_k << endl;
        }
        BST<int, string> is;
        min_k = is.min_key() ;
        if(min_k != 0) {
            cout << "Incorrect result of min_key of empty BST. Expected 0 but got : " << min_k << endl;
        }
        BST<int, int> ii;
        min_k = ii.min_key() ;
        if(min_k != 0) {
            cout << "Incorrect result of min_key of empty BST. Expected 0 but got : " << min_k << endl;
        }
        BST<int, float> i_f;
        min_k = i_f.min_key() ;
        if(min_k != 0) {
            cout << "Incorrect result of min_key of empty BST. Expected 0 but got : " << min_k << endl;
        }
        BST<float, string> fs;
        min_k = fs.min_key() ;
        if(min_k != 0) {
            cout << "Incorrect result of min_key of empty BST. Expected 0 but got : " << min_k << endl;
        }
        BST<float, int> fi;
        min_k = fi.min_key() ;
        if(min_k != 0) {
            cout << "Incorrect result of min_key of empty BST. Expected 0 but got : " << min_k << endl;
        }
        BST<float, float> ff;
        min_k = ff.min_key() ;
        if(min_k != 0) {
            cout << "Incorrect result of min_key of empty BST. Expected 0 but got : " << min_k << endl;
        }


        //


        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        min_k = balanced_bst.min_key() ;
        if(min_k != 10) {
            cout << "Incorrect result of min_key. Expected 10 but got : " << min_k << endl;
        }

        int vals2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 20};
        BST<string, int> unbalanced_bst;
        for(int i = 0; i < 10; i++) {
            unbalanced_bst.insert(to_string(vals2[i]) + " data", vals2[i]);
        }
        min_k = unbalanced_bst.min_key() ;
        if(min_k != 20) {
            cout << "Incorrect result of min_key. Expected 20 but got : " << min_k << endl;
        }

        BST<string, int> unbalanced_neg;
        int unb[5] = {0, -1 ,-2, -3, -4};
        for(int i = 0; i < 5; i++) {
            unbalanced_neg.insert(to_string(unb[i]) + " data", unb[i]);
        }
        min_k = unbalanced_neg.min_key() ;
        if(min_k != 0) {
            cout << "Incorrect result of min_key. Expected 0 but got : " << min_k << endl;
        }

        BST<string, int> pos_unb;
        int unb2[5] = {0, 1, 2, 3, 4};
        for(int i = 0; i < 5; i++) {
            pos_unb.insert(to_string(unb2[i]) + " data", unb2[i]);
        }
        min_k = pos_unb.min_key() ;
        if(min_k != 4) 
        {
            cout << "Incorrect result of min_key. Expected 4 but got : " << min_k << endl;
        }

        string str_max_k;
        BST<string, string> pride;
        pride.insert("bisexual", "purple");
        pride.insert("gay", "green");
        pride.insert("lesbian", "orange");
        pride.insert("straight", "white");
        str_min_k = pride.min_key() ;
        if(str_min_k != "white") 
        {
            cout << "Incorrect result of min_key. Expected white but got : " << str_min_k << endl;
        }
        pride.insert("wait, that's not a flag", "zebra");
        str_min_k = pride.min_key() ;
        if(str_min_k != "zebra") 
        {
            cout << "Incorrect result of min_key. Expected zebra but got : " << str_min_k << endl;
        }

        BST<int, string> alph;
        alph.insert(6, "F");
        alph.insert(5, "E");
        alph.insert(1, "A");
        alph.insert(10, "J");
        str_min_k = alph.min_key() ;
        if(str_min_k != "J") 
        {
            cout << "Incorrect result of min_key. Expected \"J\" but got : " << str_min_k << endl;
        }
        alph.remove("J");
        str_min_k = alph.min_key() ;
        if(str_min_k != "F") 
        {
            cout << "Incorrect result of min_key. Expected \"F\" but got : " << str_min_k << endl;
        }

        BST<int, float> floaty;
        floaty.insert(5, 5.1);
        floaty.insert(200, 0.1);
        floaty.insert(50000, 0.3);
        floaty.insert(0, 15.5);
        min_k = floaty.min_key() ;
        if(min_k != 15.5) 
        {
            cout << "Incorrect result of min_key. Expected \"15.5\" but got : " << min_k << endl;
        }

        BST<string, string> punct;
        punct.insert("question mark", "?");
        punct.insert("big A", "A");
        punct.insert("quote", "'");
        punct.insert("little a", "a");
        punct.insert("interrobang", "?!");
        punct.insert("tilde", "~");
        str_min_k = punct.min_key() ;
        if(str_min_k != "~") 
        {
            cout << "Incorrect result of min_key. Expected \"~\" but got : " << str_min_k << endl;
        }
        punct.remove("~");
        str_min_k = punct.min_key() ;
        if(str_min_k != "a") 
        {
            cout << "Incorrect result of min_key. Expected \"a\" but got : " << str_min_k << endl;
        }

        BST<float, float> one;
        one.insert(1.1, 13.4);
        min_k = one.min_key() ;
        if(min_k != 13.4) 
        {
            cout << "Incorrect result of min_key. Expected \"13.4\" but got : " << min_k << endl;
        }
        one.remove(13.4);
        min_k = one.min_key() ;
        if(min_k != 0) 
        {
            cout << "Incorrect result of min_key of empty BST. Expected 0 but got : " << min_k << endl;
        }

    } catch(exception& e) {
        cerr << "Error in determining key of max node in bst : " << e.what() << endl;
    }
}

void test_min_data() 
{
    try {

        string min_str;

        //empties
        BST<string, string> str_str;
        min_str = str_str.min_data();
        if(min_str != "") {
            cout << "Incorrect result finding min_data of empty BST. Expected nothing but got : " << min_str << endl;
        }
        BST<string, float> str_fl;
        min_str = str_fl.min_data();
        if(min_str != "0") {
            cout << "Incorrect result finding min_data of empty BST. Expected 0 but got : " << min_str << endl;
        }
        BST<string, int> str_int;
        min_str = str_int.min_data();
        if(min_str != "0") {
            cout << "Incorrect result finding min_data of empty BST. Expected 0 but got : " << min_str << endl;
        }
        BST<float, string> fl_str;
        min_str = fl_str.min_data();
        if(min_str != "") {
            cout << "Incorrect result finding min_data of empty BST. Expected nothing but got : " << min_str << endl;
        }
        BST<float, float> fl_fl;
        min_str = fl_fl.min_data();
        if(min_str != "0") {
            cout << "Incorrect result finding min_data of empty BST. Expected 0 but got : " << min_str << endl;
        }
        BST<float, int> fl_int;
        min_str = fl_int.min_data();
        if(min_str != "0") {
            cout << "Incorrect result finding min_data of empty BST. Expected 0 but got : " << min_str << endl;
        }
        BST<int, string> int_str;
        max_min_strstr = int_str.min_data();
        if(min_str != "") {
            cout << "Incorrect result finding min_data of empty BST. Expected nothing but got : " << min_str << endl;
        }
        BST<int, float> int_float;
        min_str = int_float.min_data();
        if(min_str != "0") {
            cout << "Incorrect result finding min_data of empty BST. Expected 0 but got : " << min_str << endl;
        }
        BST<int, int> int_int;
        min_str = int_int.min_data();
        if(min_str != "0") {
            cout << "Incorrect result finding min_data of empty BST. Expected 0 but got : " << min_str << endl;
        }

        //


        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        min_str = balanced_bst.min_data();
        if(min_str != "1 data") {
            cout << "Incorrect result of min_data. Expected \"1 data\" but got : " << min_str << endl;
        }

        int vals2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 20};
        BST<string, int> unbalanced_bst;
        for(int i = 0; i < 10; i++) {
            unbalanced_bst.insert(to_string(vals2[i]) + " data", vals2[i]);
        }
        min_str = unbalanced_bst.min_data();
        if(min_str != "1 data") {
            cout << "Incorrect result of min_data. Expected \"1 data\" but got : " << min_str << endl;
        }

        BST<string, int> unbalanced_neg;
        int unb[5] = {0, -1 ,-2, -3, -4};
        for(int i = 0; i < 5; i++) {
            unbalanced_neg.insert(to_string(unb[i]) + " data", unb[i]);
        }
        min_str = unbalanced_neg.min_data();
        if(min_str != "-4 data") {
            cout << "Incorrect result of max_data. Expected \"-4 data\" but got : " << min_str << endl;
        }

        BST<string, int> pos_unb;
        int unb2[5] = {0, 1, 2, 3, 4};
        for(int i = 0; i < 5; i++) {
            pos_unb.insert(to_string(unb2[i]) + " data", unb2[i]);
        }
        max_str = pos_unb.max_data();
        if(max_str != "4 data") {
            cout << "Incorrect result of max_data. Expected \"4 data\" but got : " << max_str << endl;
        }

        BST<string, string> fruit;
        fruit.insert("apple", "red");
        fruit.insert("grape", "purple");
        fruit.insert("banana", "yellow");
        fruit.insert("pear", "greenish");
        fruit.insert("orange", "orange");
        min_str = fruit.min_data();
        if(min_str != "pear") 
        {
            cout << "Incorrect result of min_data. Expected \"pear\" but got : " << min_str << endl;
        }

        BST<string, string> punct;
        punct.insert("question mark", "?");
        punct.insert("big A", "A");
        punct.insert("quote", "'");
        punct.insert("little a", "a");
        punct.insert("interrobang", "?!");
        punct.insert("tilde", "~");
        min_str = punct.min_data();
        if(min_str != "quote") 
        {
            cout << "Incorrect result of min_data. Expected \"quote\" but got : " << min_str << endl;
        }

        BST<int, float> floaty;
        floaty.insert(5, 5.1);
        floaty.insert(200, 0.1);
        floaty.insert(50000, 0.3);
        floaty.insert(0, 15.5);
        min_str = floaty.min_data();
        if(min_str != "200") 
        {
            cout << "Incorrect result of min_data. Expected \"200\" but got : " << min_str << endl;
        }

        BST<int, string> alph;
        alph.insert(6, "F");
        alph.insert(5, "E");
        alph.insert(1, "A");
        alph.insert(10, "J");
        min_str = alph.min_data();
        if(min_str != "1") 
        {
            cout << "Incorrect result of min_data. Expected \"1\" but got : " << min_str << endl;
        }

        BST<string, float> whatever;
        whatever.insert("boo", 3155.5);
        whatever.insert("booga", 3155.4);
        whatever.insert("rahrah", 3200.0;)
        whatever.insert("gooblegooble", 15004.1);
        whatever.insert("ahaha", 2353.2);
        min_str = whatever.min_data();
        if(min_str != "ahaha") 
        {
            cout << "Incorrect result of min_data. Expected \"ahaha\" but got : " << min_str << endl;
        }

    } catch(exception& e) {
        cerr << "Error in determining data of min node in bst : " << e.what() << endl;
    }
}

void test_min_key() 
{
    try {
        int min_k;

        //empties
        BST<string, string> ss;
        min_k = ss.min_key();
        if(min_k != 0) {
            cout << "Incorrect result of min_key of empty BST. Expected 0 but got : " << min_k << endl;
        }
        BST<string, int> si;
        min_k = si.min_key();
        if(min_k != 0) {
            cout << "Incorrect result of min_key of empty BST. Expected 0 but got : " << min_k << endl;
        }
        BST<string, float> sf;
        min_k = sf.min_key();
        if(min_k != 0) {
            cout << "Incorrect result of min_key of empty BST. Expected 0 but got : " << min_k << endl;
        }
        BST<int, string> is;
        min_k = is.min_key();
        if(min_k != 0) {
            cout << "Incorrect result of min_key of empty BST. Expected 0 but got : " << min_k << endl;
        }
        BST<int, int> ii;
        min_k = ii.min_key();
        if(min_k != 0) {
            cout << "Incorrect result of min_key of empty BST. Expected 0 but got : " << min_k << endl;
        }
        BST<int, float> i_f;
        min_k = i_f.min_key();
        if(min_k != 0) {
            cout << "Incorrect result of min_key of empty BST. Expected 0 but got : " << min_k << endl;
        }
        BST<float, string> fs;
        min_k = fs.min_key();
        if(min_k != 0) {
            cout << "Incorrect result of min_key of empty BST. Expected 0 but got : " << min_k << endl;
        }
        BST<float, int> fi;
        min_k = fi.min_key();
        if(min_k != 0) {
            cout << "Incorrect result of min_key of empty BST. Expected 0 but got : " << min_k << endl;
        }
        BST<float, float> ff;
        min_k = ff.min_key();
        if(min_k != 0) {
            cout << "Incorrect result of min_key of empty BST. Expected 0 but got : " << min_k << endl;
        }


        //


        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        min_k = balanced_bst.min_key();
        if(min_k != 1) {
            cout << "Incorrect result of min_key. Expected 1 but got : " << min_k << endl;
        }

        int vals2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 20};
        BST<string, int> unbalanced_bst;
        for(int i = 0; i < 10; i++) {
            unbalanced_bst.insert(to_string(vals2[i]) + " data", vals2[i]);
        }
        min_k = unbalanced_bst.min_key() ;
        if(min_k != 1) {
            cout << "Incorrect result of min_key. Expected 1 but got : " << min_k << endl;
        }

        BST<string, int> unbalanced_neg;
        int unb[5] = {0, -1 ,-2, -3, -4};
        for(int i = 0; i < 5; i++) {
            unbalanced_neg.insert(to_string(unb[i]) + " data", unb[i]);
        }
        min_k = unbalanced_neg.min_key() ;
        if(min_k != -4) {
            cout << "Incorrect result of min_key. Expected -4 but got : " << min_k << endl;
        }

        BST<string, int> pos_unb;
        int unb2[5] = {0, 1, 2, 3, 4};
        for(int i = 0; i < 5; i++) {
            pos_unb.insert(to_string(unb2[i]) + " data", unb2[i]);
        }
        min_k = pos_unb.min_key() ;
        if(min_k != 0) 
        {
            cout << "Incorrect result of min_key. Expected 0 but got : " << min_k << endl;
        }

        string str_min_k;
        BST<string, string> pride;
        pride.insert("bisexual", "purple");
        pride.insert("gay", "green");
        pride.insert("lesbian", "orange");
        pride.insert("straight", "white");
        str_min_k = pride.min_key() ;
        if(str_min_k != "green") 
        {
            cout << "Incorrect result of min_key. Expected green but got : " << str_min_k << endl;
        }
        pride.insert("asexual", "a color");
        str_min_k = pride.min_key() ;
        if(str_min_k != "a color") 
        {
            cout << "Incorrect result of min_key. Expected a color but got : " << str_min_k << endl;
        }

        BST<int, string> alph;
        alph.insert(6, "F");
        alph.insert(5, "E");
        alph.insert(1, "A");
        alph.insert(10, "J");
        str_min_k = alph.min_key() ;
        if(str_min_k != "A") 
        {
            cout << "Incorrect result of min_key. Expected \"A\" but got : " << str_min_k << endl;
        }
        alph.remove("A");
        str_min_k = alph.min_key() ;
        if(str_min_k != "E") 
        {
            cout << "Incorrect result of min_key. Expected \"E\" but got : " << str_min_k << endl;
        }

        BST<int, float> floaty;
        floaty.insert(5, 5.1);
        floaty.insert(200, 0.1);
        floaty.insert(50000, 0.3);
        floaty.insert(0, 15.5);
        min_k = floaty.min_key() ;
        if(min_k != 0.1) 
        {
            cout << "Incorrect result of min_key. Expected \"0.1\" but got : " << min_k << endl;
        }

        BST<string, string> punct;
        punct.insert("question mark", "?");
        punct.insert("big A", "A");
        punct.insert("quote", "'");
        punct.insert("little a", "a");
        punct.insert("interrobang", "?!");
        punct.insert("tilde", "~");
        str_min_k = punct.min_key() ;
        if(str_min_k != "'") 
        {
            cout << "Incorrect result of min_key. Expected \"'\" but got : " << str_min_k << endl;
        }
        punct.remove("'");
        str_min_k = punct.min_key() ;
        if(str_min_k != "?") 
        {
            cout << "Incorrect result of min_key. Expected \"?\" but got : " << str_min_k << endl;
        }

        BST<float, float> one;
        one.insert(1.1, 13.4);
        min_k = one.min_key() ;
        if(min_k != 13.4) 
        {
            cout << "Incorrect result of min_key. Expected \"13.4\" but got : " << min_k << endl;
        }
        one.remove(13.4);
        min_k = one.min_key() ;
        if(min_k != 0) 
        {
            cout << "Incorrect result of min_key of empty BST. Expected 0 but got : " << min_k << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining key of min node in bst : " << e.what() << endl;
    }
}

void test_successor() 
{
    try {
        int succ_int;
        string succ_str;
        float succ_fl;

        BST<string, string> ss;
        succ_str = ss.successor("hi");
        if(succ_str != "") 
        {
            cout << "Incorrect result of successor of empty string. Expected nothing but got : " << succ_str << endl;
        }
        BST<string, int> si;
        BST<string, float> sf;
        BST<int, string> is;
        BST<int, int> ii;
        BST<int, float> i_f;
        BST<float, string> fs;
        BST<float, int> fi;
        BST<float, float> ff;


        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        succ_int = balanced_bst.successor(4);
        if(succ_int != 5) {
            cout << "Incorrect result of successor of 4. Expected 5 but got : " << succ_int << endl;
        }
        succ_int = balanced_bst.successor(7);
        if(succ_int != 8) {
            cout << "Incorrect result of successor of 7. Expected 8 but got : " << succ_int << endl;
        }
        succ_int = balanced_bst.successor(10);
        if(succ_int != 0) {
            cout << "Incorrect result of successor of 10. Expected 0 but got : " << succ_int << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining successor in bst : " << e.what() << endl;
    }
}

void test_in_order() 
{
    try {
        BST<string, int> bst;
        for(int i = 1; i <= 10; i++) {
            bst.insert("some data", i);
        }
        string bst_str = bst.in_order();
        if(bst_str != "1 2 3 4 5 6 7 8 9 10") {
            cout << "Incorrect in_order result after inserting keys 1-10 in order. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert("some data", vals[i]);
        }
        bst_str = balanced_bst.in_order();
        if(bst_str != "1 2 3 4 5 6 7 8 9 10") {
            cout << "Incorrect in_order result after inserting keys {5, 2, 7, 1, 3, 4, 6, 9, 8, 10}. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error getting keys in_order from bst : " << e.what() << endl;
    }
}

void test_trim() 
{
    try {
        BST<string,int> bst;
        int vals[3] = {1, 0, 2};
        for(int i = 0; i < 3; i++) {
            bst.insert(to_string(vals[i])+" data", vals[i]);
        }
        bst.trim(1,2);
        string bst_str = bst.to_string();
        if(bst_str != "1 2") {
            cout << "Incorrect tree after trimming 1 0 2 with low=1, high=2. Expected 1 2 but got : " << bst_str << endl;
        }
        BST<string, int> bst2;
        int vals2[5] = {3, 0, 4, 2, 1};
        for(int i = 0; i < 5; i++) {
            bst2.insert(to_string(vals2[i])+" data", vals2[i]);
        }
        bst2.trim(1,3);
        bst_str = bst2.to_string();
        if(bst_str != "3 2 1") {
            cout << "Incorrect tree after trimming 3 0 4 2 1 with low=1, high=3. Expected 3 2 1 but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in trimming the bst : " << e.what() << endl;
    }
}

void test_binhex()
{
    try {
        BST<string,string>* bst1 = create_bst<string,string>("binhex.txt");
        string bin1 = "111010100101";
        string expected_hex1 = "EA5";

        string hex1 = convert<string,string>(bst1, bin1);
        delete bst1;

//         if(hex1!=expected_hex1) {
//             cout << "Incorrect result converting " << bin1 << " to hex. Expected : " << expected_hex1 << ", but got : " << hex1 << endl;
//         }
       
//     } catch(exception& e) {
//         cerr << "Error converting binary to hex : " << e.what() << endl;
//     }

//     try {
//         BST<string,string>* bst2 = create_bst<string,string>("binhex.txt");
//         string bin2 = "110101";
//         string expected_hex2 = "35";

//         string hex2 = convert<string,string>(bst2, bin2);
//         delete bst2;

//         if(hex2!=expected_hex2) {
//             cout << "Incorrect result converting " << bin2 << " to hex. Expected : " << expected_hex2 << ", but got : " << hex2 << endl;
//         }
       
//     } catch(exception& e) {
//         cerr << "Error converting binary to hex : " << e.what() << endl;
//     }
// }

int main() {
    
    // test_empty();
    // test_insert();
    // test_get();
    // test_remove();
    // test_max_data();
    // test_max_key();
    // test_min_data();
    // test_min_key();
    // test_successor();
    test_in_order();
    // test_trim();
    // test_binhex();

    cout << "Testing completed" << endl;
    
    return 0;
}
