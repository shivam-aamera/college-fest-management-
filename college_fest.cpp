#include <bits/stdc++.h>
using namespace std;
map<string, int> Activities_choice;
map<int, int> rating_arrangements;
map<int, int> rating_activities;
map<string, int> Most_liked_activity;
map<string, int> Most_liked_food;
void graph_rating_arrangements();
void graph_rating_activities();
void graph_most_liked_activities();
void graph_most_liked_food();
class Dicey
{
protected:
    int score;

public:
    Dicey()
    {
        score = 0;
    }
    Dicey(int s)
    {
        score = s;
    }
};
class Event
{
protected:
    string event_name;
    string timing;
    string address;
    string theme;

public:
    virtual void show_Details() = 0; // Abstract classes and pure virtual functions
};                                   // Function overriding
class Person
{
protected:
    string name;
    int age;
    char gender;
};
class Participant;
class Organiser : public Event
{
protected:
    string Organiser_name;
    vector<string> activities;
    vector<vector<string>> Participants_info;
    friend void CHOICE(Participant &p, Organiser &o, vector<string> &);

public:
    Organiser(string en, string t, string on, string ad, string th, string ac1, string ac2, string ac3, string ac4, string ac5)
    {
        event_name = en;
        timing = t;
        Organiser_name = on;
        address = ad;
        theme = th;
        activities.push_back(ac1);
        activities.push_back(ac2);
        activities.push_back(ac3);
        activities.push_back(ac4);
        activities.push_back(ac5);
        Activities_choice[ac1] = 1;
        Activities_choice[ac2] = 2;
        Activities_choice[ac3] = 3;
        Activities_choice[ac4] = 4;
        Activities_choice[ac5] = 5;
    }
    void getParticipant_details(vector<vector<string>> v)
    {
        Participants_info = v;
    }
    void showParticipant_details()
    {
        system("pause");
        for (int i = 0; i < Participants_info.size(); i++)
        {
            cout << i + 1 << ". Participant details: " << endl;
            int j = 0;
            cout << "Name: " << Participants_info[i][j] << endl;
            j++;
            cout << "Age: " << Participants_info[i][j] << endl;
            j++;
            cout << "Gender: " << Participants_info[i][j] << endl;
            j++;
            cout << "Arrival timing: " << Participants_info[i][j] << endl;
            j++;
            cout << "Activities in which he/she took part: " << endl;
            for (; j < Participants_info[i].size(); j++)
            {
                cout << Participants_info[i][j] << "\n";
            }
            cout << "\n";
        }
    }
    void show_Details()
    {
        system("cls");
        cout << "Event name: " << event_name << endl;
        cout << "Timings are: " << timing << endl;
        cout << "Organiser: " << Organiser_name << endl;
        cout << "Venue of the event is: " << address << endl;
        cout << "Activities :\n"
             << "1." << activities[0] << "\n"
             << "2." << activities[1] << "\n"
             << "3." << activities[2] << "\n"
             << "4." << activities[3] << "\n"
             << "5." << activities[4] << endl;
    }
    void AIM_SHOOTING(Participant &p);
    void FOOD_STALL(Participant &p);
    void GUESS_GAME(Participant &p);
    void LUCKY_CHAIR(Participant &p);
    void DICE_GAME(Participant &p1, Participant &p2);
    ~Organiser()
    {
        system("cls");
        char res;
        cout << "Want to see all participant details:(y/n) "
             << "\n";
        cin >> res;
        if (res == 'y')
        {
            showParticipant_details();
            system("pause");
        }
        else
        {
            system("pause");
        }
        cout << "\n";
        graph_rating_arrangements();
        cout << "\n";
        graph_rating_activities();
        cout << "\n";
        graph_most_liked_activities();
        cout << "\n";
        graph_most_liked_food();
        cout << "\n";
    }
};
class Participant : public Person, public Dicey
{
    int arrival_timing;
    int coins;
    friend void Organiser::AIM_SHOOTING(Participant &p);
    friend void Organiser::FOOD_STALL(Participant &p);
    friend void Organiser::GUESS_GAME(Participant &p);
    friend void Organiser::LUCKY_CHAIR(Participant &p);
    friend void Organiser::DICE_GAME(Participant &p1, Participant &p2);
    friend void Feedback_form(Participant &p);
    friend void CHOICE(Participant &p, Organiser &o, vector<string> &);

public:
    Participant()
    {
    }
    Participant(string n, int a, char g, int c, int s) : Dicey(s)
    {
        name = n;
        age = a;
        gender = g;
        coins = c;
    }
    vector<string> set_data()
    {
        system("cls");
        cout << "Enter your name: "
             << "\n";
        cin >> name;
        cout << "Enter your age: "
             << "\n";
        cin >> age;
        cout << "Enter your gender: "
             << "\n";
        cin >> gender;
        cout << "Enter the number of coins you have: "
             << "\n";
        cin >> coins;
        cout << "Enter your Arrival time: "
             << "\n";
        cin >> arrival_timing;
        Offer(arrival_timing);
        vector<string> v;
        v.push_back(name);
        v.push_back(to_string(age));
        if (gender == 'M')
        {
            v.push_back("M");
        }
        else
        {
            v.push_back("F");
        }
        v.push_back(to_string(arrival_timing));
        return v;
    }
    void Offer(int time)
    {
        if (time <= 8)
        {
            cout << "\nOffer: You have arrived earlier so here is your offer your coins have been increased by 400. Now, go and have fun!\n\n";
            coins += (400);
        }
        else if (time <= 9)
        {
            cout << "\nOffer: You have arrived earlier so here is your offer your coins have been increased by 200. Now, go and have fun!\n\n";
            coins += (200);
        }
    }
    void show_Partcipant_Details()
    {
        system("cls");
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Initially coins are: " << coins << endl;
    }
    bool operator<(Participant const &obj)
    {
        if (this->score < obj.score)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator>(Participant const &obj)
    {
        if (this->score > obj.score)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator==(Participant const &obj)
    {
        if (this->score == obj.score)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    ~Participant()
    {
        if (this->name != "Bot")
        {
            Feedback_form(*this);
        }
    }
};
void CHOICE(Participant &p, Organiser &o, vector<string> &v) // Choice function where user will be given choices what he/she wants to do
{
beginning:
    system("cls");
    cout << "\n"
         << p.name << "\n\n";
    char gotostart;
    int ch;
    cout << "\n\n\n\tMENU";
    cout << "\n\n\t1. Display Event details: ";
    cout << "\n\n\t2. Organiser Details: ";
    cout << "\n\n\t3. Event Theme: ";
    cout << "\n\n\t4. Activities: ";
    cout << "\n\n\t5. Exit";
    cout << "\n\nWhat is your Choice (1/2/3/4/5): ";
    cin >> ch;
    switch (ch)
    {
    case 1:
        system("cls");
        cout << "\nUSER: "
             << p.name << "\n\n";
        cout << "\t\t\t--------Displaying Event Details---------\n";
        o.show_Details();
        cout << "\n\n";
        break;
    case 2:
        system("cls");
        cout << "\nUSER: "
             << p.name << "\n\n";
        cout << "\t\t--------Organiser Details---------\n";
        cout << o.Organiser_name;
        cout << "\n\n";
        break;
    case 3:
        system("cls");
        cout << "\nUSER: "
             << p.name << "\n\n";
        cout << "\t\t--------Event Theme---------\n";
        cout << o.theme;
        cout << "\n\n";
        break;
    case 4:
        system("cls");
        cout << "\nUSER: "
             << p.name << "\n\n";
        cout << "\t\t--------Activities---------\n\n";
        cout << "\nCoins remaining: " << p.coins << "\n";
        int ch_1;
        cout << "\n\n\t1. AIM SHOOTING: ";
        cout << "\n\n\t2. FOOD STALL: ";
        cout << "\n\n\t3. GUESS GAME: ";
        cout << "\n\n\t4. DICE GAME(2 Player Game): ";
        cout << "\n\n\t5. LUCKY_CHAIR: ";
        cout << "\n\n\t6. GO BACK TO MAIN MENU: ";
        cout << "\n\nWhat is your Choice (1/2/3/4/5/6): ";
        cin >> ch_1;
        switch (ch_1)
        {
        case 1:
            try
            {
                if ((p.coins - 300) < 0)
                {
                    throw p.coins;
                }
                o.AIM_SHOOTING(p);
                v.push_back("AIM SHOOTING");
                p.coins -= 300;
                cout << "\nCoins remaining: " << p.coins << "\n\n";
            }
            catch (int p_coins)
            {
                cout << "\nException: Coins are not enough\n\n";
                cout << "\nCoins remaining: " << p.coins << "\n\n";
            }
            break;
        case 2:
            o.FOOD_STALL(p);
            v.push_back("FOOD STALL");
            break;
        case 3:
            try
            {
                if ((p.coins - 200) < 0)
                {
                    throw p.coins;
                }
                o.GUESS_GAME(p);
                v.push_back("GUESS GAME");
                p.coins -= 200;
                cout << "\nCoins remaining: " << p.coins << "\n\n";
            }
            catch (int p_coins)
            {
                cout << "\n\nException: Coins are not enough\n\n";
                cout << "\nCoins remaining: " << p.coins << "\n\n";
            }
            break;
        case 4:
            try
            {
                if ((p.coins - 400) < 0)
                {
                    throw p.coins;
                }
                cout << "2 players are: You and a bot\n\n";
                Participant p_bot("Bot", 100, 'M', 10000, 0);
                o.DICE_GAME(p, p_bot);
                v.push_back("DICE GAME");
                p.coins -= 400;
                cout << "\nCoins remaining: " << p.coins << "\n\n";
            }
            catch (int p_coins)
            {
                cout << "\n\nException: Coins are not enough\n\n";
                cout << "\nCoins remaining: " << p.coins << "\n\n";
            }
            break;
        case 5:
            try
            {
                if ((p.coins - 500) < 0)
                {
                    throw p.coins;
                }
                o.LUCKY_CHAIR(p);
                v.push_back("LUCKY CHAIR");
                p.coins -= 500;
                cout << "\nCoins remaining: " << p.coins << "\n\n";
            }
            catch (int p_coins)
            {
                cout << "\n\nException: Coins are not enough\n\n";
                cout << "\nCoins remaining: " << p.coins << "\n\n";
            }
            break;
        case 6:
            CHOICE(p, o, v);
        }
        break;
    case 6:
        system("cls");
        cout << "\n";
        cout << "\t\t\n\n--------EXIT---------\n\n\n";
        break;
    }
    cout << "Would you like to something else? Y / N: ";
    cin >> gotostart;
    if (gotostart == 'Y' || gotostart == 'y')
    {
        goto beginning;
    }
    else
    {
        cout << "\n";
        cout << "\t\t\n\n--------EXIT---------\n\n";
        cout << "\n";
    }
}
void Organiser::LUCKY_CHAIR(Participant &p1)
{
    system("cls");
    cout << "\nUSER: "
         << p1.name << "\n\n";
    cout << "\n\n\t\t\t\tLUCKY CHAIR" << endl;
    cin.ignore();
    cout << "\nPress Enter to start the game... " << endl;
    cin.get();
    cout << "\nRules for the game: \n"
         << "1) There will be some players(5-10) depending on your choice.\n"
         << "2) There will be chairs from 0 to n-1(n: no. of participants).\n"
         << "3) You just have to give a try to your luck and pick a number between 0 to n-1(n: no. of participants) on which chair you want to sit in.\n";
    string Respond;
    cout << "Are you ready to play the game? yes/no" << endl;
    cin >> Respond;
    if (Respond == "yes")
    {
        cout << endl;
        cout << "Good Luck!" << endl;
    }
    else
    {
        cout << "Okay Good Bye!" << endl;
        return;
    }
    int num_of_players;
    int chair_num;
    cout << "\nHow many players do you want to play with(Pick any number between 5 to 10)? Please Enter your choice! " << endl;
    cin >> num_of_players;
    cout << "\nPick any number between 0 to n-1(n: no. of participants) at which you want to sit: " << endl;
    cin >> chair_num;
    int move;
    int max_n = 10;
    int min_n = 1;
    int new_n;
    vector<int> chairs;
    srand(time(0));
    for (int i = 0; i < num_of_players; i++)
    {
        new_n = ((rand() % (max_n + 1 - min_n)) + min_n);
        chairs.push_back(new_n);
        cout << new_n << " ";
    }
    cout << "\n";
    int pos = 0;
    max_n = num_of_players;
    min_n = 1;
    int f;
    f = 1;
    int num_of_negatives = 0;
    srand(time(0));
    while (true)
    {
        new_n = ((rand() % (max_n + 1 - min_n)) + min_n);
        pos = (pos + new_n + 1) % num_of_players;
        if (chairs[pos] < 0)
        {
            continue;
        }
        if (pos == chair_num)
        {
            cout << "\nCurrent situation: ";
            for (int i = 0; i < num_of_players; i++)
            {
                if (chairs[i] < 0)
                {
                    num_of_negatives++;
                }
                cout << chairs[i] << " ";
            }
            cout << "\n";
            cout << "\nYou Lose! Better luck next time\n"
                 << endl;
            f = 0;
            break;
        }
        if (chairs[pos] > 0)
        {
            chairs[pos] = chairs[pos] * (-1);
        }
        int num_of_negatives = 0;
        cout << "\nCurrent situation: ";
        for (int i = 0; i < num_of_players; i++)
        {
            if (chairs[i] < 0)
            {
                num_of_negatives++;
            }
            cout << chairs[i] << " ";
        }
        cout << "\n";
        if (num_of_negatives == (num_of_players - 1))
        {
            break;
        }
    }
    if (chairs[chair_num] > 0 && f > 0)
    {
        cout << "\nYou win! Yay:)\n";
    }
}
void Organiser::DICE_GAME(Participant &p1, Participant &p2)
{
    system("cls");
    cout << "\nUSER: "
         << p1.name << "\n\n";
    cout << "\n\n\t\t\t\tDICE GAME" << endl;
    cin.ignore();
    cout << "\nPress Enter to start the game... " << endl;
    cin.get();
    cout << "\nRules for the game: \n"
         << "1) There will be 5 turns.\n"
         << "2) The player with the maximum score will win.\n";
    string Respond;
    cout << "Are you ready to take the guessing game? yes/no" << endl;
    cin >> Respond;
    if (Respond == "yes")
    {
        cout << endl;
        cout << "Good Luck!" << endl;
    }
    else
    {
        cout << "Okay Good Bye!" << endl;
        return;
    }
    vector<int> points_player_A;
    vector<int> points_player_B;
    int ran_x = 0;
    srand(time(0));
    for (int i = 0; i < 5; i++)
    {
        ran_x = rand() % 6;
        p1.score += (ran_x);
        points_player_A.push_back(ran_x);
    }
    for (int i = 0; i < 5; i++)
    {
        ran_x = rand() % 6;
        p2.score += (ran_x);
        points_player_B.push_back(ran_x);
    }
    cout << "Your points are: ";
    for (int i = 0; i < points_player_A.size(); i++)
    {
        cout << points_player_A[i] << " ";
    }
    cout << "\n";
    cout << "Bot points are: ";
    for (int i = 0; i < points_player_B.size(); i++)
    {
        cout << points_player_B[i] << " ";
    }
    cout << endl;

    if (p1 < p2)
    {
        cout << "\nBot Win\n";
        cout << "You Lose\n";
    }
    else if (p1 > p2)
    {
        cout << "\nYou Win\n";
        cout << "Bot Lose\n";
        p1.coins += 200;
        cout << "\nYou won 200 coins\n\n"
             << endl;
    }
    else if (p1 == p2)
    {
        cout << "\nIt's a Tie!\n";
    }
}
void Organiser::AIM_SHOOTING(Participant &p)
{
    system("cls");
    cout << "\nUSER: "
         << p.name << "\n\n";
    cout << "\nWelcome to this amazing aim shooting game. Good Luck!" << endl;
    vector<int> points;
    int ran_x = 0, total_points = 0;
    srand(time(0));
    for (int i = 0; i < 5; i++)
    {
        ran_x = rand() % 10;
        total_points += (ran_x);
        points.push_back(ran_x);
    }
    cout << "Your points are: ";
    for (int i = 0; i < points.size(); i++)
    {
        cout << points[i] << " ";
    }
    cout << endl;
    cout << "Total points are: " << total_points << endl;
    if (total_points >= 20)
    {
        p.coins += 50;
        cout << "\nYou won 50 coins"
             << endl;
    }
    else if (total_points >= 15)
    {
        p.coins += 25;
        cout << "\nYou won 25 coins\n\n"
             << endl;
    }
    else if (total_points >= 10)
    {
        p.coins += 10;
        cout << "\nYou won 10 coins\n\n"
             << endl;
    }
}
int menu()
{
    int choice;
    cout << "\nMenu:" << endl;
    cout << "1) Pizzas\n";
    cout << "2) Burgers\n";
    cout << "3) Momos\n";
    cout << "4) Spring rolls\n";
    cout << "5) Soft Drink\n\n";
    cout << "\nPlease Enter your Choice: ";
    cin >> choice;
    return choice;
}

void Organiser::FOOD_STALL(Participant &p)
{
beginning:
    system("cls");
    cout << "\nUSER: "
         << p.name << "\n\n";
    char gotostart;
    cout << "\nWhat would you like to have?" << endl;
    int choice = menu();
    switch (choice)
    {
    case 1:
        cout << "\t\t\t--------Your Order---------\n";
        cout << "Pizza" << endl;
        if ((p.coins - (100)) < 0)
        {
            cout << "You can't order as you don't have sufficient money" << endl;
            cout << "\nCoins remaining: " << p.coins << "\n";
            goto beginning;
        }
        cout << "Your Total Bill is: 100" << endl;
        p.coins -= (100);
        cout << "\nCoins remaining: " << p.coins << "\n";
        cout << "Thank you!! Please enjoy your meal\n";
        break;
    case 2:
        cout << "\t\t--------Your Order---------\n";
        cout << "Burger" << endl;
        if ((p.coins - (50)) < 0)
        {
            cout << "You can't order as you don't have sufficient money" << endl;
            cout << "\nCoins remaining: " << p.coins << "\n";
            goto beginning;
        }
        cout << "\nYour Total Bill is: 50" << endl;
        p.coins -= (50);
        cout << "\nCoins remaining: " << p.coins << "\n";
        cout << "Thank you!! Please enjoy your meal\n";
        break;
    case 3:
        cout << "\t\t--------Your Order---------\n";
        cout << "Momos" << endl;
        if ((p.coins - (60)) < 0)
        {
            cout << "You can't order as you don't have sufficient money" << endl;
            cout << "\nCoins remaining: " << p.coins << "\n";
            goto beginning;
        }
        cout << "\nYour Total Bill is: 60" << endl;
        p.coins -= (60);
        cout << "\nCoins remaining: " << p.coins << "\n";
        cout << "Thank you!! Please enjoy your meal\n";
        break;
    case 4:
        cout << "\t\t--------Your Order---------\n";
        cout << "Spring roll" << endl;
        if ((p.coins - (80)) < 0)
        {
            cout << "You can't order as you don't have sufficient money" << endl;
            cout << "\nCoins remaining: " << p.coins << "\n";
            goto beginning;
        }
        cout << "\nYour Total Bill is: 80" << endl;
        p.coins -= (80);
        cout << "\nCoins remaining: " << p.coins << "\n";
        cout << "Thank you!! Please enjoy your meal\n";
        break;
    case 5:
        cout << "\t\t--------Your Order---------\n";
        cout << "Soft Drink" << endl;
        if ((p.coins - (40)) < 0)
        {
            cout << "You can't order as you don't have sufficient money" << endl;
            cout << "\nCoins remaining: " << p.coins << "\n";
            goto beginning;
        }
        cout << "\nYour Total Bill is: 40" << endl;
        p.coins -= (40);
        cout << "\nCoins remaining: " << p.coins << "\n";
        cout << "Thank you!! Please enjoy your drink\n";
        break;
    }
    cout << "Would you like to order anything else? Y / N:";
    cin >> gotostart;
    if (gotostart == 'Y' || gotostart == 'y')
    {
        goto beginning;
    }
}
void Organiser::GUESS_GAME(Participant &p)
{
    system("cls");
    cout << "\nUSER: "
         << p.name << "\n\n";
    cout << "\n\n\t\t\t\tQUIZ" << endl;
    cout << "\nPress Enter to start the game... " << endl;
    cin.get();
    cout << "Rules for the game: \n"
         << "1) There will be 5 questions.\n"
         << "2) It is mandatory to answer all of them.\n"
         << "3) No points deduction for wrong answers.\n";
    string Respond;
    cout << "Are you ready to take the guessing game? yes/no" << endl;
    cin >> Respond;
    if (Respond == "yes")
    {
        cout << endl;
        cout << "Good Luck!" << endl;
    }
    else
    {
        cout << "Okay Good Bye!" << endl;
        return;
    }
    unordered_map<string, string> Questions;
    Questions["What word is spelled incorrectly in every single dictionary?"] = "Incorrectly";
    Questions["What goes up and down but can't move?"] = "A staircase";
    Questions["What goes up but never down?"] = "Your age";
    Questions["I have one head, one foot, and four legs. What am I?"] = "Your bed";
    Questions["I have teeth but cannot eat. What am I?"] = "A comb";
    int iterate = 1, points = 0, correct_ans = 0;
    string answer;
    for (auto it = Questions.begin(); it != Questions.end(); it++)
    {
        cout << "\nYour question is: \n"
             << it->first << endl;
        cout << "\nYour answer: \n";
        cin.ignore();
        getline(cin, answer);
        if (answer == it->second)
        {
            cout << "\nYou guessed it correctly!" << endl
                 << endl;
            points += (10);
            correct_ans++;
        }
        else
        {
            cout << "\nOOPS! Your guess was wrong!" << endl;
            cout << "\nThe correct answer is: " << it->second << endl;
        }
    }
    cout << "Game over!\n";
    cout << "nYou guessed " << correct_ans << " correct answer out of 5" << endl;
    cout << "You win " << points << " points\n";
    p.coins += (points * 10);
}
void Feedback_form(Participant &p)
{
    system("cls");
    int rating[2];
    char ch;
    string most_likeable[2];
    cout << "\n\nEvent Feedback Form: " << endl;
    cout << "Please provide your feedback on the following topics(Enter your Choices out of 5): " << endl;
    cout << "How would you Rate our Arrangements: " << endl;
    cin >> rating[0];
    if (rating[0] == 5)
    {
        rating_arrangements[5]++;
    }
    else if (rating[0] == 4)
    {
        rating_arrangements[4]++;
    }
    else if (rating[0] == 3)
    {
        rating_arrangements[3]++;
    }
    else if (rating[0] == 2)
    {
        rating_arrangements[2]++;
    }
    else
    {
        rating_arrangements[1]++;
    }
    cout << "Rate our activities: " << endl;
    cin >> rating[1];
    if (rating[1] == 5)
    {
        rating_activities[5]++;
    }
    else if (rating[1] == 4)
    {
        rating_activities[4]++;
    }
    else if (rating[1] == 3)
    {
        rating_activities[3]++;
    }
    else if (rating[1] == 2)
    {
        rating_activities[2]++;
    }
    else
    {
        rating_activities[1]++;
    }
    cout << "Which activity you liked the most: " << endl;
    // cin.ignore();
    cin >> ws;
    getline(cin, most_likeable[0]);
    if (most_likeable[0] == "FOOD STALL")
    {
        Most_liked_activity["FOOD STALL"]++;
    }
    else if (most_likeable[0] == "AIM SHOOTING")
    {
        Most_liked_activity["AIM SHOOTING"]++;
    }
    else if (most_likeable[0] == "GUESS GAME")
    {
        Most_liked_activity["GUESS GAME"]++;
    }
    else if (most_likeable[0] == "DICE GAME")
    {
        Most_liked_activity["DICE GAME"]++;
    }
    else if (most_likeable[0] == "LUCKY CHAIR")
    {
        Most_liked_activity["LUCKY CHAIR"]++;
    }
    cout << "Which food item you liked the most: " << endl;
    cin >> ws;
    getline(cin, most_likeable[1]);
    if (most_likeable[1] == "Pizzas")
    {
        Most_liked_food["Pizzas"]++;
    }
    else if (most_likeable[1] == "Burgers")
    {
        Most_liked_food["Burgers"]++;
    }
    else if (most_likeable[1] == "Momos")
    {
        Most_liked_food["Momos"]++;
    }
    else if (most_likeable[1] == "Spring rolls")
    {
        Most_liked_food["Spring rolls"]++;
    }
    else if (most_likeable[1] == "Soft Drink")
    {
        Most_liked_food["Soft Drink"]++;
    }
    cout << "Would you like to redeem your remaining coins back into your bank account:(Y/N) " << endl;
    cin >> ch;
    if (ch == 'Y')
    {
        p.coins = 0;
    }
    else
    {
        cout << "\nWhat would you like to purchase from your remaining coins: \n"
             << endl;
    beginning:
        char gotostart;
        int ch;
        cout << "\n\n\n\tMENU";
        cout << "\n\n\t1. Teddy Bear ";
        cout << "\n\n\t2. Chocolates ";
        cout << "\n\n\t3. Gift vouchers ";
        cout << "\n\n\t4. Gift cards  ";
        cout << "\n\nWhat is your Choice (1/2/3/4): ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\n";
            cout << "\t\t\t--------You purchased a Teddy bear!---------\n";
            p.coins = 0;
            cout << "\n\n";
            break;
        case 2:
            cout << "\n";
            cout << "\t\t--------You purchased some chocolates---------\n";
            p.coins = 0;
            cout << "\n\n";
            break;
        case 3:
            cout << "\n";
            cout << "\t\t--------Here are some Gift vouchers for you!---------\n";
            p.coins = 0;
            cout << "\n\n";
            break;
        case 4:
            cout << "\n";
            cout << "\t\t--------Here are some Gift cards for you!---------\n\n";
            p.coins = 0;
            break;
        }
    }
    cout << "Thank you for coming and your feedback. We look forward to serving you again in the near future." << endl
         << endl;
}
void graph_rating_arrangements()
{
    cout << "\nRating of our arrangements: "
         << "\n";
    for (auto it = rating_arrangements.begin(); it != rating_arrangements.end(); it++)
    {
        cout << it->first << ": ";
        for (int i = 1; i <= it->second; i++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}
void graph_rating_activities()
{
    cout << "\nRating of our activities: "
         << "\n";
    for (auto it = rating_activities.begin(); it != rating_activities.end(); it++)
    {
        cout << it->first << ": ";
        for (int i = 1; i <= it->second; i++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}
void graph_most_liked_activities()
{
    cout << "\nMost liked activities: "
         << "\n";
    for (auto it = Most_liked_activity.begin(); it != Most_liked_activity.end(); it++)
    {
        cout << it->first << ": ";
        for (int i = 1; i <= it->second; i++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}
void graph_most_liked_food()
{
    cout << "\nMost liked food: "
         << "\n";
    for (auto it = Most_liked_food.begin(); it != Most_liked_food.end(); it++)
    {
        cout << it->first << ": ";
        for (int i = 1; i <= it->second; i++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}
int main()
{
    system("cls");
    Organiser obj1("ANUGOONJ", "2-10", "ANUGOONJ TEAM", "INDRAPRASTHA UNIVERSITY", "ETHNIC", "AIM SHOOTING", "FOOD STALL", "GUESS GAME", "DICE GAME(2 Player Game)", "LUCKY CHAIR");
    cout << "\n\n\t\t--------ANUGOONJ WELCOMES YOU ALL! HAVE FUN :)---------\n\n";
    system("pause");
    int n;
    cout << "\nEnter the number of partcipants: "
         << "\n";
    cin >> n;
    Participant obj[n];
    cout << "\n";
    vector<vector<string>> v_final;
    for (int i = 0; i < n; i++)
    {
        vector<string> v;
        v = obj[i].set_data();
        v_final.push_back(v);
        system("pause");
        cout << "\n";
    }
    for (int i = 0; i < n; i++)
    {
        cout << "\n\n";
        obj[i].show_Partcipant_Details();
        system("pause");
        cout << "\n\n";
        CHOICE(obj[i], obj1, v_final[i]);
        cout << "\n\n";
    }
    obj1.getParticipant_details(v_final);
    return 0;
}