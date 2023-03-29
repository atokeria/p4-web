// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "List.h"
#include "unit_test_framework.h"

using namespace std;

// Add your test cases here

TEST(test_stub) {
    // Add test code here
    ASSERT_TRUE(true);
}

//Testing for initialisation of empty list
TEST(test_empty_list) {
    List<int> empty_list;
    ASSERT_TRUE(empty_list.empty());
    ASSERT_TRUE(empty_list.size() == 0);
    empty_list.push_back(1);
    ASSERT_TRUE(!empty_list.empty());
    ASSERT_TRUE(empty_list.size() == 1);
}

// Testing initialisation of one element and test of push back
TEST(test_list_default_ctor) {
    List<int> one_list;

    one_list.push_back(1);
    ASSERT_EQUAL(1,one_list.size());
    ASSERT_EQUAL(1,*one_list.begin());
}

// Testing initialisation of 10 with 2 of the same elements

TEST(test_same_element_init) {
    List<int> ten_list;

    ten_list.push_back(1);
    ten_list.push_back(2);
    ten_list.push_back(3);
    ten_list.push_back(4);
    ten_list.push_back(5);
    ten_list.push_back(6);
    ten_list.push_back(6);
    ten_list.push_back(7);
    ten_list.push_back(8);
    ten_list.push_back(9);

    ASSERT_EQUAL(10,ten_list.size());
}

// Testing the push front function
TEST(test_push_front1) {
    List<int> front_list;

    front_list.push_back(1);
    front_list.push_back(2);
    front_list.push_front(10);

    ASSERT_EQUAL(10,front_list.front());
    ASSERT_EQUAL(3,front_list.size());

}

// Testing the push front function
TEST(test_push_front2) {
    List<int> front_list;

    front_list.push_front(10);

    ASSERT_EQUAL(10,front_list.front());
    ASSERT_EQUAL(1,front_list.size());
}

// Testing the front and back functions with 1 variable
TEST(test_front_back1) {
    List<int> push_list;

    push_list.push_back(1);

    ASSERT_EQUAL(1,push_list.front());
    ASSERT_EQUAL(1,push_list.back());
}

// Testing the front and back functions with 2 variable
TEST(test_front_back2) {
    List<int> push_list;

    push_list.push_back(1);
    push_list.push_back(2);

    ASSERT_EQUAL(1,push_list.front());
    ASSERT_EQUAL(2,push_list.back());
}

// Testing the front and back functions with 3 variable
TEST(test_front_back3) {
    List<int> push_list;

    push_list.push_back(1);
    push_list.push_back(2);
    push_list.push_back(3);

    ASSERT_EQUAL(1,push_list.front());
    ASSERT_EQUAL(3,push_list.back());
}

// Testing pop back when there is 1 element
TEST(test_pop_back1) {
    List<int> pop_list1;

    pop_list1.push_back(1);
    pop_list1.pop_back();

    ASSERT_EQUAL(0,pop_list1.size());
    // ASSERT_EQUAL(nullptr,pop_list1.front());
    // ASSERT_EQUAL(nullptr,pop_list1.back());
}

// Testing pop back when there is 2 element
TEST(test_pop_back2) {
    List<int> pop_list2;

    pop_list2.push_back(1);
    pop_list2.push_back(2);
    pop_list2.pop_back();

    ASSERT_EQUAL(1,pop_list2.size());
    ASSERT_EQUAL(1,pop_list2.front());
    ASSERT_EQUAL(1,pop_list2.back());
}

// Testing pop back when there is 3 element
TEST(test_pop_back3) {
    List<int> pop_list3;

    pop_list3.push_back(1);
    pop_list3.push_back(2);
    pop_list3.push_back(3);
    pop_list3.pop_back();

    ASSERT_EQUAL(2,pop_list3.size());
    ASSERT_EQUAL(1,pop_list3.front());
    ASSERT_EQUAL(2,pop_list3.back());
}

// Testing pop back to clear list
TEST(test_pop_back4) {
    List<int> pop_list4;

    pop_list4.push_back(1);
    pop_list4.push_back(2);
    pop_list4.push_back(3);
    pop_list4.pop_back();
    pop_list4.pop_back();
    pop_list4.pop_back();

    ASSERT_EQUAL(0,pop_list4.size());
    // ASSERT_EQUAL(nullptr,pop_list4.front());
    // ASSERT_EQUAL(nullptr,pop_list4.back());
}

////////////////////////////////////////////////////

// Testing pop front when there is 1 element
TEST(test_pop_front1) {
    List<int> pop_list1;

    pop_list1.push_back(1);
    pop_list1.pop_front();

    ASSERT_EQUAL(0,pop_list1.size());
    // ASSERT_EQUAL(nullptr,pop_list1.front());
    // ASSERT_EQUAL(nullptr,pop_list1.back());
}

// Testing pop front when there is 2 element
TEST(test_pop_front2) {
    List<int> pop_list2;

    pop_list2.push_back(1);
    pop_list2.push_back(2);
    pop_list2.pop_front();

    ASSERT_EQUAL(1,pop_list2.size());
    ASSERT_EQUAL(2,pop_list2.front());
    ASSERT_EQUAL(2,pop_list2.back());
}

// Testing pop front when there is 3 element
TEST(test_pop_front3) {
    List<int> pop_list3;

    pop_list3.push_back(1);
    pop_list3.push_back(2);
    pop_list3.push_back(3);
    pop_list3.pop_front();

    ASSERT_EQUAL(2,pop_list3.size());
    ASSERT_EQUAL(2,pop_list3.front());
    ASSERT_EQUAL(3,pop_list3.back());
}

// Testing pop front to clear list
TEST(test_pop_front4) {
    List<int> pop_list4;

    pop_list4.push_back(1);
    pop_list4.push_back(2);
    pop_list4.push_back(3);
    pop_list4.pop_front();
    pop_list4.pop_front();
    pop_list4.pop_front();

    ASSERT_EQUAL(0,pop_list4.size());
    // ASSERT_EQUAL(nullptr,pop_list4.front());
    // ASSERT_EQUAL(nullptr,pop_list4.back());
}

// Testing empty function
TEST(test_clear_list) {
    List<int> empty_list;

    empty_list.clear();

    ASSERT_EQUAL(0,empty_list.size());
    ASSERT_TRUE(empty_list.empty());
    // ASSERT_EQUAL(nullptr,empty_list.front());
    // ASSERT_EQUAL(nullptr,empty_list.back());
}

// Testing empty function
TEST(test_clear_list1) {
    List<int> empty_list1;

    empty_list1.push_back(1);
    empty_list1.clear();

    ASSERT_EQUAL(0,empty_list1.size());
    // ASSERT_EQUAL(nullptr,empty_list.front());
    // ASSERT_EQUAL(nullptr,empty_list.back());
}

// Testing empty function
TEST(test_clear_list2) {
    List<int> empty_list2;

    empty_list2.push_back(1);
    empty_list2.push_back(2);
    empty_list2.push_back(3);
    empty_list2.clear();

    ASSERT_EQUAL(0,empty_list2.size());
    // ASSERT_EQUAL(nullptr,empty_list.front());
    // ASSERT_EQUAL(nullptr,empty_list.back());
}

// Testing empty function
TEST(test_empty1) {
    List<int> empty_list;

    empty_list.push_back(1);
    empty_list.push_back(2);
    empty_list.push_back(3);
    empty_list.clear();

    ASSERT_TRUE(empty_list.empty());
}

// Testing empty function
TEST(test_empty2) {
    List<int> empty_list;

    empty_list.push_back(1);
    empty_list.push_back(2);
    empty_list.push_back(3);

    ASSERT_TRUE(!empty_list.empty());
}

// Testing big 3
TEST(test_big3){
    List<int> big1;

    big1.push_back(1);
    big1.push_back(2);
    big1.push_back(3);

    List<int> big2 = big1;
    List<int> big3(big1);

    ASSERT_EQUAL(1,big2.front());
    ASSERT_EQUAL(1,big3.front());
}

// Testing big 3
TEST(test_big32){
    List<int> big1;

    big1.push_back(1);

    List<int> big2 = big1;
    List<int> big3(big1);

    ASSERT_EQUAL(1,big2.front());
    ASSERT_EQUAL(1,big3.front());
}

// Testing many function
TEST(test_empty3) {
    List<int> many;

    many.push_back(1);
    many.push_back(2);
    many.push_back(3);

    ASSERT_TRUE(!many.empty());

    many.clear();
    ASSERT_TRUE(many.empty());


}

//// Testing iterator functions

//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////

// Testing iterator begin with one element
TEST(test_iterator_begin1) {
    List<int> listbegin;
    listbegin.push_back(1);

    List<int>::Iterator begintester = listbegin.begin();
    ASSERT_EQUAL(1,*begintester);
}

// Testing iterator begin with three elements
TEST(test_iterator_begin2) {
    List<int> listbegin2;
    listbegin2.push_back(1);
    listbegin2.push_back(2);
    listbegin2.push_back(3);

    List<int>::Iterator begintester = listbegin2.begin();
    ASSERT_EQUAL(1,*begintester);
}

// Testing iterator end with one element
TEST(test_iterator_end1) {
    List<int> listend1;
    listend1.push_back(1);

    List<int>::Iterator endtester = listend1.end();
    List<int>::Iterator endtesterhelper = listend1.begin();

    ASSERT_NOT_EQUAL(endtesterhelper,endtester);

    //++endtester;
    //ASSERT_EQUAL(endtesterhelper,endtester);
}

// Testing iterator end with three element
TEST(test_iterator_end2) {
    List<int> listend2;
    listend2.push_back(1);
    listend2.push_back(2);
    listend2.push_back(3);

    List<int>::Iterator endtester = listend2.end();
    List<int>::Iterator endtesterhelper = listend2.begin();
    ++endtesterhelper;
    ++endtesterhelper;

    ASSERT_NOT_EQUAL(endtesterhelper,endtester);
}

// Testing iterator erase whilst sending in the iterator for first
TEST(test_iterator_erase1) {
    List<int> listerase1;
    listerase1.push_back(1);
    listerase1.push_back(2);
    listerase1.push_back(3);

    List<int>::Iterator erasetester = listerase1.begin();
    listerase1.erase(erasetester);
    ASSERT_EQUAL(2,listerase1.size());
}

// CONFIRMED DO NOT NEED
// Testing iterator erase whilst sending in the iterator for end
// TEST(test_iterator_erase2) {
//     List<int> listerase2;
//     listerase2.push_back(1);
//     listerase2.push_back(2);
//     listerase2.push_back(3);

//     List<int>::Iterator erasetester = listerase2.end();
//     listerase2.erase(erasetester);
//     ASSERT_FAIL(3,listerase2.size());
// }

// Testing iterator erase whilst sending in the iterator not for first
TEST(test_iterator_erase3) {
    List<int> listerase3;
    listerase3.push_back(1);
    listerase3.push_back(2);
    listerase3.push_back(3);

    List<int>::Iterator erasetester = listerase3.begin();
    ++erasetester;
    listerase3.erase(erasetester);

    List<int>::Iterator erasetester2 = listerase3.begin();
    ++erasetester2;

    ASSERT_EQUAL(2,listerase3.size());
    ASSERT_EQUAL(3,*erasetester2);
}

// Testing iterator erase whilst sending in the iterator not for first
TEST(test_iterator_erase4) {
    List<int> listerase4;
    listerase4.push_back(1);
    listerase4.push_back(2);
    listerase4.push_back(3);

    List<int>::Iterator erasetester = listerase4.begin();
    ++++erasetester;
    listerase4.erase(erasetester);

    ASSERT_EQUAL(2,listerase4.size());
    ASSERT_EQUAL(2,listerase4.back());
}

// Testing iterator insert with no elements
TEST(test_iterator_inser1) {
    List<int> listinsert1;
    List<int>::Iterator inserttester = listinsert1.begin();
    listinsert1.insert(inserttester, 1);

    ASSERT_EQUAL(1, listinsert1.front());
    ASSERT_EQUAL(1, listinsert1.size());
}

// Testing iterator insert with no elements
TEST(test_iterator_inser10) {
    List<int> listinsert1;
    List<int>::Iterator inserttester = listinsert1.begin();
    listinsert1.insert(inserttester, 1);
    listinsert1.insert(inserttester, 2);
    listinsert1.insert(inserttester, 3);

    ASSERT_EQUAL(1, listinsert1.front());
    ASSERT_EQUAL(3, listinsert1.back());
    ASSERT_EQUAL(3, listinsert1.size());

    inserttester = listinsert1.begin();
    ASSERT_TRUE(*inserttester == 1);
    ++inserttester;
    ASSERT_TRUE(*inserttester == 2);
    ++inserttester;
    ASSERT_TRUE(*inserttester == 3);

    listinsert1.insert(inserttester, 5);
    ASSERT_TRUE(*inserttester == 3);
    --inserttester;
    ASSERT_TRUE(*inserttester == 5);
    --inserttester;
    ASSERT_TRUE(*inserttester == 2);
}

// Testing iterator insert with one element
TEST(test_iterator_inser2) {
    List<int> listinsert2;
    listinsert2.push_back(1);
    List<int>::Iterator inserttester = listinsert2.begin();
    listinsert2.insert(inserttester, 2);

    ASSERT_EQUAL(2, listinsert2.front());
    ASSERT_EQUAL(1, listinsert2.back());
    ASSERT_EQUAL(2, listinsert2.size());
}

// Testing iterator insert with one element but sending end
TEST(test_iterator_inser3) {
    List<int> listinsert3;
    listinsert3.push_back(1);

    List<int>::Iterator inserttester = listinsert3.end();
    listinsert3.insert(inserttester, 2);

    ASSERT_EQUAL(1, listinsert3.front());
    ASSERT_EQUAL(2, listinsert3.back());
    ASSERT_EQUAL(2, listinsert3.size());
}

// Testing iterator insert with three element but sending begin
TEST(test_iterator_inser4) {
    List<int> listinsert4;
    listinsert4.push_back(1);
    listinsert4.push_back(2);
    listinsert4.push_back(3);

    List<int>::Iterator inserttester = listinsert4.begin();
    listinsert4.insert(inserttester, 2);

    ASSERT_EQUAL(2, listinsert4.front());
    ASSERT_EQUAL(3, listinsert4.back());
    ASSERT_EQUAL(4, listinsert4.size());
}

// Testing iterator insert with three element but sending begin + 1
TEST(test_iterator_inser5) {
    List<int> listinsert5;
    listinsert5.push_back(1);
    listinsert5.push_back(2);
    listinsert5.push_back(3);

    List<int>::Iterator inserttester = listinsert5.begin();
    ++inserttester;
    listinsert5.insert(inserttester, 10);

    List<int>::Iterator inserttester2 = listinsert5.begin();
    ++inserttester2;

    ASSERT_EQUAL(1, listinsert5.front());
    ASSERT_EQUAL(3, listinsert5.back());
    ASSERT_EQUAL(10,*inserttester2);
    ASSERT_EQUAL(4, listinsert5.size());
}

// Testing iterator insert with three element but sending end
TEST(test_iterator_inser6) {
    List<int> listinsert6;
    listinsert6.push_back(1);
    listinsert6.push_back(2);
    listinsert6.push_back(3);

    List<int>::Iterator inserttester = listinsert6.end();
    listinsert6.insert(inserttester, 10);

    ASSERT_EQUAL(1, listinsert6.front());
    ASSERT_EQUAL(10, listinsert6.back());
    ASSERT_EQUAL(4, listinsert6.size());
}

// Testing iterator big three
TEST(test_iterator_big3) {
    List<int> big3_1;
    big3_1.push_back(1);
    big3_1.push_back(2);
    big3_1.push_back(3);
    List<int>::Iterator bigtester1 = big3_1.begin();
    List<int>::Iterator bigtester2 = bigtester1;
    List<int>::Iterator bigtester3 = List<int>::Iterator(bigtester1);

    ASSERT_EQUAL(1,*bigtester2);
    ASSERT_EQUAL(1,*bigtester3);

    ++bigtester2;
    ASSERT_EQUAL(2, * bigtester2);
    
}

// Testing iterator ++
TEST(test_iterator_plus_plus) {
    List<int> plusser;
    plusser.push_back(1);
    plusser.push_back(2);
    plusser.push_back(3);

    List<int>::Iterator plustester = plusser.begin();
    ++plustester;
    ASSERT_EQUAL(2,*plustester);
    ASSERT_EQUAL(3,*++plustester);
}

// Testing iterator --
TEST(test_iterator_minus_minus) {
    List<int> plusser;
    plusser.push_back(1);
    plusser.push_back(2);
    plusser.push_back(3);

    List<int>::Iterator plustester = plusser.begin();
    ++plustester;
    ASSERT_EQUAL(2,*plustester);
    ASSERT_EQUAL(1,*--plustester);
}

// Testing iterator that its all connected
TEST(test_iterator_connect1) {
    List<int> connect;
    connect.push_back(1);
    connect.push_back(2);
    connect.push_back(3);
    connect.push_back(4);
    connect.push_back(5);
    
    int counter = 0;
    for(List<int>::Iterator plustester = connect.begin();
                plustester != connect.end(); ++plustester){
        counter++;
    }

    ASSERT_EQUAL(counter,connect.size());
}

// Testing iterator ==
TEST(test_iterator_equal_equal) {
    List<int> equals;
    equals.push_back(1);
    equals.push_back(2);
    equals.push_back(3);

    List<int>::Iterator equaltester = equals.begin();
    List<int>::Iterator equaltester2 = equals.begin();

    ASSERT_TRUE(equaltester == equaltester2);
}

// Testing iterator !=
TEST(test_iterator_not_equal) {
    List<int> notequals;
    notequals.push_back(1);
    notequals.push_back(2);
    notequals.push_back(3);

    List<int>::Iterator notequaltester = notequals.begin();
    List<int>::Iterator notequaltester2 = notequals.begin();
    ++notequaltester2;

    ASSERT_TRUE(notequaltester != notequaltester2);
}

// Testing iterator loopy
TEST(test_iterator_not_equal2) {
    List<int> loop;
    loop.push_back(1);
    loop.push_back(2);
    loop.push_back(3);

    int ass = 0;
    for (List<int>::Iterator looptester = loop.begin();
            looptester != loop.end(); ++looptester){
        ass++;
    }
    ASSERT_EQUAL(ass, 3);
}

/////////////////////////////////////////////

TEST(stupid){
    List<int> my_list;

    int size = 0;
    my_list.empty();
    my_list.size();
    cout << (my_list.size() == size) << endl;

    my_list.push_front(42);
    my_list.push_back(42);

    my_list.front() = 73;
    my_list.back() = 73;

    my_list.pop_front();
    my_list.pop_back();

    List<int> list2(my_list);
    list2 = my_list;

    List<int>::Iterator iter = my_list.begin();
    my_list.insert(iter, 42);
    iter = my_list.begin();
    my_list.erase(iter);
    iter = my_list.begin();

    List<int>::Iterator iter2 = my_list.end();
    const List<int>::Iterator iter3 = iter2;

    bool b = iter == iter2;
    b = iter3 == my_list.end();
    b = my_list.end() == iter3;
    my_list.push_front(42);
    my_list.push_back(42);
    iter = my_list.begin();
    b = iter != iter2;
    b = iter3 != my_list.end();
    b = my_list.end() != iter3;
    cout << b << endl;
    ++iter;

    cout << *iter << endl;

    List<int>::Iterator iter_cpy(iter);
    iter_cpy = iter;

    cout << *++--iter << endl;
    cout << *--++my_list.begin() << endl;

    my_list.insert(my_list.begin(), 3);
    my_list.erase(my_list.begin());

    List<int> list3;
    list3.push_back(3);
    cout << *list3.begin() << endl;

    List<int> list4;
    list4.push_back(4);
    cout << list4.size() << endl;

    my_list.clear();

}

TEST_MAIN()
