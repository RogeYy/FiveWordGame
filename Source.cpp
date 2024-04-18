#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
#include <typeinfo>




//не работат из-за window
void  Text_Font(sf::Text Text, sf::Font Font) {
    Text.setFont(Font);
    Text.setFillColor(sf::Color::Black);
    Text.setScale(sf::Vector2f(0.85, 0.85));
}

void  Zodat_kordi(sf::RectangleShape Sprite, short size_x, short size_y, short x, short y, short red, short green, short blue) {
    Sprite.setSize(sf::Vector2f(size_x, size_y));
    Sprite.setPosition(x, y);
    Sprite.setFillColor(sf::Color::Color(red, green, blue));
}


int main()
{
    setlocale(LC_ALL, "Russian");
    //переменные

    ///////////// ТЕКСТ
    std::vector <std::string> All_Word;
    std::vector <std::string> random_word_easy, random_word_medium, random_word_hard;//импорт из файла
    random_word_easy = { "арбуз", "автор", "актер", "балет", "басня", "бегун", "белка", "блоха", "вафля", "ведро", "вирус", "газон", "глина",
        "гость", "губка", "дверь", "девиз", "демон", "диско", "дочка", "жабры", "жених", "жетон", "живот", "жизнь", "забег", "забор", "завод",
        "зефир", "игрок", "идеал", "изгой", "исток", "исход", "катер", "кинза", "клоун", "кореш", "кость", "купол", "лазер", "лидер", "лимон",
        "лодка", "ложка", "лютик", "магия", "мажор", "малыш", "маляр", "манго", "мячик", "навык", "намек", "нарды", "немой", "нефть", "номер",
        "обман", "одежа", "океан", "омлет", "отдых", "отель", "пакет", "парус", "пасть", "песня", "песок", "почка", "птица", "радио", "раунд",
        "речка", "рифма", "роман", "ружье", "рулет", "рыбка", "рычаг", "салют", "санки", "сапог", "страх", "сынок", "табло", "талия", "тепло",
        "ткань", "товар", "толпа", "тоска", "точка", "труба", "уголь", "узбек", "улица", "успех", "устав", "учеба", "факел", "ферма", "фильм",
        "финал", "фокус", "хвост", "хлыст", "хомяк", "цветы", "центр", "цифра", "часть", "червь", "чипсы", "чудак", "шарик", "шепот", "шесть",
        "школа", "шляпа", "шприц", "щегол", "экран", "юноша", "ягода", "ярлык" };

    std::string string_word;
    std::ifstream Word("all_world.txt");


    //ввод всех существующих слов
    if (Word.is_open()) {
        while (getline(Word, string_word)) {
            if (string_word != "") {
                for (int s_w = 0; s_w < 5; s_w++) if (string_word[s_w] == 'ё') string_word[s_w] = 'е';
                All_Word.push_back(string_word);
                random_word_hard.push_back(string_word);
            }
        }
    }

    const short RAND_Easy = size(random_word_easy);

    //рандомное и случайное слово
    std::string cin_word;
    std::string hidden_word = random_word_easy[rand() % RAND_Easy];//рандомное слово
    std::wstring w_window_hidden_word_t;



    ///////////// SFNL
    sf::RenderWindow window(sf::VideoMode(650, 850), "5 word");
    window.setKeyRepeatEnabled(false);

    //клава
    sf::Keyboard keyboard;

    //текстуры
    sf::Texture knopka;
    if (!knopka.loadFromFile("ikone/table_knopka.png")) {}



    //спрайты
    sf::Sprite sprite_knopka;
    sprite_knopka.setTexture(knopka);
    sf::RectangleShape fon(sf::Vector2f(650, 850));

    //шрифт
    sf::Font Font;
    if (!Font.loadFromFile("arial.ttf")) {}

    //текст
    sf::Text word[33], Win, Lose, word_is_apcent, window_hidden_word, text_in_menu;
    Win.setFont(Font);
    Win.setFillColor(sf::Color::Black);
    Win.setScale(sf::Vector2f(0.85, 0.85));
    Lose.setFont(Font);
    Lose.setFillColor(sf::Color::Black);
    Lose.setScale(sf::Vector2f(0.85, 0.85));
    word_is_apcent.setFont(Font);
    word_is_apcent.setFillColor(sf::Color::Black);
    word_is_apcent.setScale(sf::Vector2f(0.85, 0.85));
    Text_Font(window_hidden_word, Font);
    text_in_menu.setFont(Font);
    text_in_menu.setFillColor(sf::Color::Black);
    text_in_menu.setScale(sf::Vector2f(1, 1));


    for (short i = 0; i < 33; i++) {
        word[i].setFont(Font);
        word[i].setFillColor(sf::Color::Black);
    }


    Win.setString(L"Слово угадано, Победа!");
    Lose.setString(L"Слово не угаданно, Поражение!");
    word_is_apcent.setString(L"Такого слова не сущаествует!");

    std::wstring qwerty_string = L"ЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ";
    for (short i = 0; i < 32 ; i++) word[i].setString(qwerty_string[i]);
    word_is_apcent.setPosition(sf::Vector2f(150, 500));
    word[0].setPosition(sf::Vector2f(35, 575));
    word[1].setPosition(sf::Vector2f(85, 575));
    word[2].setPosition(sf::Vector2f(135, 575));
    word[3].setPosition(sf::Vector2f(185, 575));
    word[4].setPosition(sf::Vector2f(235, 575));
    word[5].setPosition(sf::Vector2f(285, 575));
    word[6].setPosition(sf::Vector2f(335, 575));
    word[7].setPosition(sf::Vector2f(382, 575));
    word[8].setPosition(sf::Vector2f(432, 575));
    word[9].setPosition(sf::Vector2f(486, 575));
    word[10].setPosition(sf::Vector2f(535, 575));
    word[11].setPosition(sf::Vector2f(585, 575));
    word[12].setPosition(sf::Vector2f(59, 650));
    word[13].setPosition(sf::Vector2f(108, 650));
    word[14].setPosition(sf::Vector2f(160, 650));
    word[15].setPosition(sf::Vector2f(211, 650));
    word[16].setPosition(sf::Vector2f(259, 650));
    word[17].setPosition(sf::Vector2f(310, 650));
    word[18].setPosition(sf::Vector2f(359, 650));
    word[19].setPosition(sf::Vector2f(410, 650));
    word[20].setPosition(sf::Vector2f(460, 650));
    word[21].setPosition(sf::Vector2f(505, 650));
    word[22].setPosition(sf::Vector2f(560, 650));
    word[23].setPosition(sf::Vector2f(85, 725));
    word[24].setPosition(sf::Vector2f(135, 725));
    word[25].setPosition(sf::Vector2f(182, 725));
    word[26].setPosition(sf::Vector2f(232, 725));
    word[27].setPosition(sf::Vector2f(285, 725));
    word[28].setPosition(sf::Vector2f(334, 725));
    word[29].setPosition(sf::Vector2f(385, 725));
    word[30].setPosition(sf::Vector2f(435, 725));
    word[31].setPosition(sf::Vector2f(483, 725));

    //табличка
    sf::Text table[5][5];
    for (short int i = 0; i < 5; i++) {
        for (short int j = 0; j < 5; j++) {
            table[i][j].setFont(Font);
            table[i][j].setFillColor(sf::Color::Black);
        }
    }
    char table_char[5][5];
    short int ii = 0, jj = 0;

    //все буквы    
    std::string All_word = "йцукенгшщзхъфывапролджэячсмитьбю";
    std::wstring All_word_wchar = L"йцукенгшщзхъфывапролджэячсмитьбю";
    std::string All_letter = "фисвуапршолдьтщзйкыегмцчня--------------------хъжбюэ-";
    std::wstring All_bid_letter = L"ФИСВУАПРШОЛДЬТЩЗЙКЫЕГМЦЧНЯ--------------------ХЪЖБЮЭ-";

    //буловские переменные
    bool pause = true;
    bool win = false;
    bool lose = false;
    bool PROVERKA = true;
    bool start_game = false;
    bool tochno = false;
    bool nastroiki = false;





    while (window.isOpen())
    {
        Sleep(10);

        //проверка на закрытие файла(я сам это кста пишу)
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
        /*if (event.type == sf::Event::LostFocus)
            window.pause();

        if (event.type == sf::Event::GainedFocus)
            myGame.resume();*/

        window.clear();
        window.draw(fon);

        //      //
        // меню //
        //      //


        if (start_game == false) {
            //таблички в меню
            //первая таболичка: вход
            fon.setSize(sf::Vector2f(450, 75));
            fon.setPosition(100, 200);
            fon.setFillColor(sf::Color::Color(173, 255, 47));
            window.draw(fon);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x >= 100 && sf::Mouse::getPosition(window).y >= 200 &&
                sf::Mouse::getPosition(window).x <= 550 && sf::Mouse::getPosition(window).y <= 275) start_game = true;

            /*вторая табличка : настройки
            fon.setSize(sf::Vector2f(450, 75));
            fon.setPosition(100, 300);
            fon.setFillColor(sf::Color::Color(173, 255, 47));
            window.draw(fon);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x >= 100 && sf::Mouse::getPosition(window).y >= 300 &&
                sf::Mouse::getPosition(window).x <= 550 && sf::Mouse::getPosition(window).y <= 375) //заводские*/

            //третья табличка: выход
            fon.setSize(sf::Vector2f(450, 75));
            fon.setPosition(100, 400);
            fon.setFillColor(sf::Color::Color(173, 255, 47));
            window.draw(fon);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x >= 100 && sf::Mouse::getPosition(window).y >= 400 &&
                sf::Mouse::getPosition(window).x <= 550 && sf::Mouse::getPosition(window).y <= 475) window.close();

            fon.setPosition(0, 0);
            fon.setSize(sf::Vector2f(650, 850));
            fon.setFillColor(sf::Color::Color(255, 255, 255));

            //текст в меню
            //название игры
            text_in_menu.setString(L"Пять букв");
            text_in_menu.setScale(sf::Vector2f(1.5, 1.5));
            text_in_menu.setPosition(220, 50);
            window.draw(text_in_menu);
            //вход в игру
            text_in_menu.setScale(sf::Vector2f(1, 1));
            text_in_menu.setString(L"Начать игру");
            text_in_menu.setPosition(240, 215);
            window.draw(text_in_menu);
            /*настройки
            text_in_menu.setString(L"Настройки");
            text_in_menu.setPosition(250, 315);
            window.draw(text_in_menu);*/
            //выход
            text_in_menu.setString(L"Выход");
            text_in_menu.setPosition(280, 415);
            window.draw(text_in_menu);
        }


        //         //
        //поле игры//
        //         //
        if (start_game) {
            //загаданное слово
            if (size(w_window_hidden_word_t) < 5) {
                for (char& h_w : hidden_word) w_window_hidden_word_t.push_back(All_word_wchar[std::distance(All_word.begin(), find(All_word.begin(), All_word.end(), h_w))]);
            }


            //табличка 5 на 5
            for (short int i = 0; i < 5; i++) {
                for (short int j = 0; j < 5; j++) {
                    sprite_knopka.setScale(sf::Vector2f(0.17, 0.17));
                    sprite_knopka.setPosition(sf::Vector2f(120 + 85 * j, 100 * i));
                    if (table_char[i][j] == '_') sprite_knopka.setColor(sf::Color(200, 200, 200));
                    else if (table_char[i][j] == '+') sprite_knopka.setColor(sf::Color(255, 165, 0));
                    else if (table_char[i][j] == '*') sprite_knopka.setColor(sf::Color(0, 255, 0));
                    window.draw(sprite_knopka);
                    sprite_knopka.setColor(sf::Color(255, 255, 255));
                }
            }
            //клавиатура
            short int Count = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 12 - i; j++) {
                    if (Count < 32) {
                        sprite_knopka.setScale(sf::Vector2f(0.1, 0.1));
                        sprite_knopka.setPosition(sf::Vector2f(25 + 50 * j + 25 * i, 575 + 75 * i));

                        if (All_word[Count] == '_') sprite_knopka.setColor(sf::Color(200, 200, 200));
                        else if (All_word[Count] == '+') sprite_knopka.setColor(sf::Color(255, 165, 0));
                        else if (All_word[Count] == '*') sprite_knopka.setColor(sf::Color(0, 255, 0));
                        window.draw(sprite_knopka);
                        sprite_knopka.setColor(sf::Color(255, 255, 255));
                    }
                    Count++;
                }
            }
            for (short int i = 0; i < 33; i++) window.draw(word[i]);





            //буквы
            if (pause) {
                for (short int value = sf::Keyboard::A; value < sf::Keyboard::Slash; value++) {
                    if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(value)) && jj < 5 && All_bid_letter[value] != '-') {
                        table[ii][jj].setString(All_bid_letter[value]);
                        switch (value) {
                        case 1:
                            table[ii][jj].setPosition(sf::Vector2f(142 + 85 * jj, 100 * ii + 15));
                            break;
                        case 8:
                            table[ii][jj].setPosition(sf::Vector2f(141 + 85 * jj, 100 * ii + 15));
                            break;
                        case 14:
                            table[ii][jj].setPosition(sf::Vector2f(141 + 85 * jj, 100 * ii + 15));
                            break;
                        case 18:
                            table[ii][jj].setPosition(sf::Vector2f(142 + 85 * jj, 100 * ii + 15));
                            break;
                        case 21:
                            table[ii][jj].setPosition(sf::Vector2f(142 + 85 * jj, 100 * ii + 15));
                            break;
                        case 48:
                            table[ii][jj].setPosition(sf::Vector2f(140 + 85 * jj, 100 * ii + 15));
                            break;
                        case 50:
                            table[ii][jj].setPosition(sf::Vector2f(142 + 85 * jj, 100 * ii + 15));
                            break;
                        default:
                            table[ii][jj].setPosition(sf::Vector2f(144 + 85 * jj, 100 * ii + 15));
                            break;
                        }
                        window.draw(table[ii][jj]);
                        if (jj < 5)jj++;
                        cin_word.push_back(All_letter[value]);
                        pause = false;
                    }
                }
                //стереть
                if (keyboard.isKeyPressed(sf::Keyboard::BackSpace) && jj >= 0 && cin_word.size() != 0) {
                    if (jj > 0) jj--;
                    cin_word.pop_back();
                    table[ii][jj].setString(L"");
                    pause = false;
                }
                if (keyboard.isKeyPressed(sf::Keyboard::Escape)) {
                    tochno = true;
                }
            }
            else if (event.type == sf::Event::KeyReleased) pause = true;



            //выход в главное меню
            if (tochno) {
                pause = false;
                //табличка: Покинуть игру?
                fon.setSize(sf::Vector2f(450, 150));
                fon.setPosition(100, 275);
                fon.setFillColor(sf::Color::Color(230, 230, 230));
                window.draw(fon);

                text_in_menu.setString(L"Покинуть игру?");
                text_in_menu.setPosition(210, 300);
                text_in_menu.setScale(sf::Vector2f(1, 1));
                window.draw(text_in_menu);
                //Zodat_kordi(fon, 100, 50, 200, 200, 173, 255, 47);
                //да
                fon.setSize(sf::Vector2f(100, 50));
                fon.setPosition(175, 350);
                fon.setFillColor(sf::Color::Color(173, 255, 47));
                window.draw(fon);

                text_in_menu.setString(L"Да");
                text_in_menu.setPosition(205, 355);
                window.draw(text_in_menu);

                //нет
                fon.setSize(sf::Vector2f(100, 50));
                fon.setPosition(375, 350);
                fon.setFillColor(sf::Color::Color(173, 255, 47));
                window.draw(fon);

                text_in_menu.setString(L"Нет");
                text_in_menu.setPosition(400, 355);
                window.draw(text_in_menu);

                fon.setPosition(0, 0);
                fon.setSize(sf::Vector2f(650, 850));
                fon.setFillColor(sf::Color::Color(255, 255, 255));

                //да: Выход
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x >= 175 && sf::Mouse::getPosition(window).y >= 350 &&
                    sf::Mouse::getPosition(window).x <= 275 && sf::Mouse::getPosition(window).y <= 400) {
                    start_game = false;
                    pause = true;
                    jj = 0;
                    ii = 0;
                    for (short int i = 0; i < 5; i++) {
                        for (short int j = 0; j < 5; j++) {
                            table[i][j].setString(L" ");
                        }
                    }
                    for (short int i = 0; i < 5; i++) {
                        for (short int j = 0; j < 5; j++) {
                            table_char[i][j] = ' ';
                        }
                    }
                    hidden_word = random_word_easy[rand() % RAND_Easy];//рандомное слово
                    All_word = "йцукенгшщзхъфывапролджэячсмитьбю";
                    tochno = false;
                    w_window_hidden_word_t.clear();
                }
                else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x >= 375 && sf::Mouse::getPosition(window).y >= 350 &&
                    sf::Mouse::getPosition(window).x <= 475 && sf::Mouse::getPosition(window).y <= 400) {
                    tochno = false;
                    pause = true;
                }
            }


            //существует ли слово
            if (find(All_Word.begin(), All_Word.end(), cin_word) == All_Word.end()) PROVERKA = false;
            else PROVERKA = true;

            if (jj >= 5 && PROVERKA == false) window.draw(word_is_apcent);

            //ввод слова 
            std::string All_word_proverka = "йцукенгшщзхъфывапролджэячсмитьбю";
            if (keyboard.isKeyPressed(sf::Keyboard::Enter) && jj >= 5 && PROVERKA) {
                for (short int j = 0; j < 5;)/*проверка букв*/ {
                    if (find(hidden_word.begin(), hidden_word.end(), cin_word[j]) == hidden_word.end()) {
                        All_word[distance(All_word.begin(), find(All_word.begin(), All_word.end(), cin_word[j]))] = '_';
                        table_char[ii][j] = '_';
                        j++;
                    }
                    else if (hidden_word[j] == cin_word[j]) {
                        if (find(All_word.begin(), All_word.end(), cin_word[j]) == All_word.end())
                            All_word[distance(All_word_proverka.begin(), find(All_word_proverka.begin(), All_word_proverka.end(), cin_word[j]))] = '*';
                        All_word[distance(All_word.begin(), find(All_word.begin(), All_word.end(), cin_word[j]))] = '*';
                        table_char[ii][j] = '*';
                        j++;
                    }
                    else {
                        All_word[distance(All_word.begin(), find(All_word.begin(), All_word.end(), cin_word[j]))] = '+';
                        table_char[ii][j] = '+';
                        j++;
                    }
                }
                ii++;
                jj = 0;
                if (hidden_word == cin_word) {
                    win = true;
                    jj = 0;
                    ii = 0;
                    for (short int i = 0; i < 5; i++) {
                        for (short int j = 0; j < 5; j++) {
                            table[i][j].setString(L" ");
                        }
                    }
                    for (short int i = 0; i < 5; i++) {
                        for (short int j = 0; j < 5; j++) {
                            table_char[i][j] = ' ';
                        }
                    }
                    hidden_word = random_word_easy[rand() % RAND_Easy];//рандомное слово
                    All_word = "йцукенгшщзхъфывапролджэячсмитьбю";
                    w_window_hidden_word_t.clear();
                }
                cin_word.clear();
            }
            if (win) {
                pause = false;
                //поле вывода новой игры
                fon.setPosition(100, 70);
                fon.setSize(sf::Vector2f(450, 600));
                fon.setFillColor(sf::Color::Color(240, 240, 240));
                window.draw(fon);
                fon.setPosition(0, 0);
                fon.setSize(sf::Vector2f(650, 850));
                fon.setFillColor(sf::Color::Color(255, 255, 255));

                //кнопка начала новой игры
                fon.setSize(sf::Vector2f(300, 50));
                fon.setPosition(175, 550);
                fon.setFillColor(sf::Color::Color(173, 255, 47));
                window.draw(fon);
                fon.setPosition(0, 0);
                fon.setSize(sf::Vector2f(650, 850));
                fon.setFillColor(sf::Color::Color(255, 255, 255));

                //текст победы
                Win.setPosition(180, 157);
                window.draw(Win);
                Win.setString(L"Новая игра");
                Win.setPosition(250, 557);
                window.draw(Win);
                Win.setString(L"Слово угадано, Победа!");

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x >= 175 && sf::Mouse::getPosition(window).y >= 550 &&
                    sf::Mouse::getPosition(window).x <= 475 && sf::Mouse::getPosition(window).y <= 600) {
                    win = false;
                    pause = true;
                    w_window_hidden_word_t.clear();
                }
            }

            if (lose) {
                pause = false;
                //поле вывода новой игры
                fon.setPosition(100, 70);
                fon.setSize(sf::Vector2f(450, 600));
                fon.setFillColor(sf::Color::Color(240, 240, 240));
                window.draw(fon);
                fon.setPosition(0, 0);
                fon.setSize(sf::Vector2f(650, 850));
                fon.setFillColor(sf::Color::Color(255, 255, 255));

                //кнопка начала новой игры
                fon.setSize(sf::Vector2f(300, 50));
                fon.setPosition(175, 550);
                fon.setFillColor(sf::Color::Color(173, 255, 47));
                window.draw(fon);
                fon.setPosition(0, 0);
                fon.setSize(sf::Vector2f(650, 850));
                fon.setFillColor(sf::Color::Color(255, 255, 255));

                //текст 
                Lose.setPosition(135, 157);
                window.draw(Lose);
                Lose.setString(L"Загаданное слово: ");
                Lose.setPosition(sf::Vector2f(165, 200));
                window.draw(Lose);
                Lose.setString(w_window_hidden_word_t);
                Lose.setPosition(sf::Vector2f(395, 200));
                window.draw(Lose);
                Lose.setString(L"Новая игра");
                Lose.setPosition(250, 557);
                window.draw(Lose);
                Lose.setString(L"Слово не угаданно, Поражение!");

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x >= 175 && sf::Mouse::getPosition(window).y >= 550 &&
                    sf::Mouse::getPosition(window).x <= 475 && sf::Mouse::getPosition(window).y <= 600) {
                    lose = false;
                    pause = true;
                    w_window_hidden_word_t.clear();
                }
            }

            for (short int i = 0; i < 5; i++) {
                for (short int j = 0; j < 5; j++) {
                    window.draw(table[i][j]);
                }
            }

            if (ii >= 5) {
                lose = true;
                jj = 0;
                ii = 0;
                for (short int i = 0; i < 5; i++) {
                    for (short int j = 0; j < 5; j++) {
                        table[i][j].setString(L" ");
                    }
                }
                for (short int i = 0; i < 5; i++) {
                    for (short int j = 0; j < 5; j++) {
                        table_char[i][j] = ' ';
                    }
                }
                hidden_word = random_word_easy[rand() % RAND_Easy];//рандомное слово
                All_word = "йцукенгшщзхъфывапролджэячсмитьбю";
            }
        }



        window.display();
    }
    return 0;
}