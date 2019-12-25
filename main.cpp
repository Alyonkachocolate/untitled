Cell comp_arrangement(int x, int y) {
    Cell chip[10][10];
    for (auto &i : chip) {
        for (Cell &j : i) {
            j = freee;
        }
    }
    srand(time(NULL));

//  Четырехпалубный
    int position, rand1, start_;
    position = rand() % 2;
    // 0 - горизонтально; 1 - вертикально
    rand1 = rand() % 10;//буква 65-rand1
    start_ = rand() % 10;
    if (start_ >= 7) start_ = rand() % 7;
    if (position == 1) for (int i = start_; i < start_ + 4; i++) chip[i][rand1] = ship;
    if (position == 0) for (int i = start_; i < start_ + 4; i++) chip[rand1][i] = ship;
    int line, column, k = 1;
    if (position == 0) {
        line = rand1;
        column = start_;
        for (int i = line - 1; i <= line + 1; i++) {
            for (int j = column - 1; j <= column + 4; j++) {
                if ((i < 10) && (i >= 0) && (j < 10) && (j >= 0)) k = 1; else k = 0;
                if (k == 1 && chip[i][j] != ship) chip[i][j] = discovered;
            }
        }
    } else {
        line = start_;
        column = rand1;
        for (int i = line - 1; i <= line + 4; i++) {
            for (int j = column - 1; j <= column + 1; j++) {
                if ((i < 10) && (i >= 0) && (j < 10) && (j >= 0)) k = 1; else k = 0;
                if (k == 1 && chip[i][j] != ship) chip[i][j] = discovered;
            }

        }
    }

    // Трёхпалубники
    for (int j = 0; j < 2; j++) {
        rand1 = 0, start_ = 0;
        position = rand() % 2;
        int u = 0;
        while (u != 3) {
            rand1 = rand() % 10;
            start_ = rand() % 10;
            if (start_ >= 8) start_ = (rand() % 8);
            if (position == 0)
                for (int i = start_; i < start_ + 3; i++)
                    if (chip[rand1][i] == freee) u++;
            if (position == 1)
                for (int i = start_; i < start_ + 3; i++)
                    if (chip[i][rand1] == freee) u++;
            if (u < 3) u = 0;
        }
        if (position == 1) for (int i = start_; i < start_ + 3; i++) chip[i][rand1] = ship;
        if (position == 0) for (int i = start_; i < start_ + 3; i++) chip[rand1][i] = ship;
        if (position == 0) {
            line = rand1;
            column = start_;
            for (int i = line - 1; i <= line + 1; i++) {
                for (int j = column - 1; j <= column + 3; j++) {
                    if ((i < 10) && (i >= 0) && (j < 10) && (j >= 0)) k = 1; else k = 0;
                    if (k == 1) if (chip[i][j] != ship) chip[i][j] = discovered;
                }
            }
        } else {
            line = start_;
            column = rand1;
            for (int i = line - 1; i <= line + 3; i++) {
                for (int j = column - 1; j <= column + 1; j++) {
                    if ((i < 10) && (i >= 0) && (j < 10) && (j >= 0)) k = 1; else k = 0;
                    if (k == 1 && chip[i][j] != ship) chip[i][j] = discovered;
                }

            }
        }
    }


    // Двухпалубники
    for (int j = 0; j < 3; j++) {
        rand1 = 0, start_ = 0;
        position = rand() % 2;
        int u = 0;
        while (u != 2) {
            rand1 = rand() % 10;
            start_ = rand() % 10;
            if (start_ == 9) start_ = (rand() % 9);
            if (position == 0)
                for (int i = start_; i < start_ + 2; i++)
                    if (chip[rand1][i] == freee) u++;
            if (position == 1)
                for (int i = start_; i < start_ + 2; i++)
                    if (chip[i][rand1] == freee) u++;
            if (u < 2) u = 0;
        }
        if (position == 1) for (int i = start_; i < start_ + 2; i++) chip[i][rand1] = ship;
        if (position == 0) for (int i = start_; i < start_ + 2; i++) chip[rand1][i] = ship;
        if (position == 0) {
            line = rand1;
            column = start_;
            for (int i = line - 1; i <= line + 1; i++) {
                for (int j = column - 1; j <= column + 2; j++) {
                    if ((i < 10) && (i >= 0) && (j < 10) && (j >= 0)) k = 1; else k = 0;
                    if (k == 1) if (chip[i][j] != ship) chip[i][j] = discovered;
                }
            }
        } else {
            line = start_;
            column = rand1;
            for (int i = line - 1; i <= line + 2; i++) {
                for (int j = column - 1; j <= column + 1; j++) {
                    if ((i < 10) && (i >= 0) && (j < 10) && (j >= 0)) k = 1; else k = 0;
                    if (k == 1 && chip[i][j] != ship) chip[i][j] = discovered;
                }

            }
        }
    }

    // Однопалубники
    for (int j = 0; j < 4; j++) {
        rand1 = 0, start_ = 0;
        int u = 0;
        while (u == 0) {
            rand1 = rand() % 10;
            start_ = rand() % 10;
            if (chip[rand1][start_] == freee) u++;
        }
        chip[rand1][start_] = ship;
        for (int i = rand1 - 1; i <= rand1 + 1; i++) {
            for (int j = start_ - 1; j <= start_ + 1; j++) {
                if ((i < 10) && (i >= 0) && (j < 10) && (j >= 0)) k = 1; else k = 0;
                if (k == 1) if (chip[i][j] != ship) chip[i][j] = discovered;
            }
        }

    }
    return chip[x][y];
}