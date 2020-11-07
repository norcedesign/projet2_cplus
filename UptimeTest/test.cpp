#include "pch.h"
#include <string>
#include "../UptimeCpp/TimeConverter.h"
using namespace std;

struct TF : public testing::Test {
    TimeConverter* c1;
    void SetUp() { c1 = new TimeConverter(); }
    void TearDown() { delete c1; }
};

TEST_F(TF, Moins_d_une_heure) {
    string expected = "5 min";
    EXPECT_EQ(c1->ConvertSectoTimeString(300), expected);
}

TEST_F(TF, Plus_d_une_Heure_Moins_d_un_Jour) {
    string expected = "10:05";
    EXPECT_EQ(c1->ConvertSectoTimeString(36300), expected);
}

TEST_F(TF, Un_jour) {
    string expected = "1 day, 5 min";
    EXPECT_EQ(c1->ConvertSectoTimeString(86700), expected);
}

TEST_F(TF, 2jours_et_plus) {
    string expected = "2 days, 01:00";
    EXPECT_EQ(c1->ConvertSectoTimeString(176400), expected);
}