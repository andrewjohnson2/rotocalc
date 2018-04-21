// Fantasy Baseball Calculator
// Andrew Johnson
// Email Andrew@AndrewJohnson.io for more information

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

struct member {
  string name;
  double run;
  double hr;
  double sb;
  double ops;
  double rbi;
  double era;
  double whip;
  double saves;
  double wins;
  double ks;
  bool selected;
  double total;
  double percentage;
  int actualstanding;
};

void addSpaces(string & teamname) {
  string underscore = "_";
  int position = teamname.find(underscore);
  while(position != teamname.npos) {
    teamname.replace(position, 1, " ");
    position = teamname.find(underscore);
  }
}

void makefalse (vector <member> & players) {
  for (int x = 0; x < players.size(); ++x) {
    players[x].selected = false;
  }
}

void zerototals (vector <member> & players) {
  for (int x = 0; x < players.size(); ++x) {
    players[x].total = 0;
  }
}

int main(int argc, char* argv[]) {
  string filename;

  ifstream stats;
  if (argc != 2) {
    cerr << "Usage [filename]" << endl;
    exit(0);
  }

  filename = argv[1];

  stats.open(filename.c_str());
  member temp;
  vector <member> players;
  for (int x = 0; x < 12; ++x) {
    stats >> temp.name >> temp.run >> temp.hr >> temp.rbi >> temp.sb >> temp.ops >> temp.ks
    >> temp.wins >> temp.era >> temp.whip >> temp.saves;
    players.push_back(temp);
  }

  zerototals(players);
  makefalse(players);
  for (double w = 12; w > 0; --w) {
    int best = 0;
    int bestindex;
    int tieindex = -1;
    int tie3 = -1;
    int q = 0;
    bool twotie = false;
    for (q = 0; q < 12; ++q) {
      if ((players[q].run > best) && !(players[q].selected)) {
        bestindex = q;
        best = players[q].run;
        tieindex = -1;
        tie3 = -1;
        twotie = false;
      }
      else if (players[q].run == best && !(players[q].selected) && !twotie) {
        tieindex = q;
        twotie = true;
      }
      else if (players[q].run == best && !(players[q].selected) && twotie) {
        tie3 = q;
      }
    }
    if (tieindex == -1 && tie3 == -1) {
      players[bestindex].total = w + players[bestindex].total;
      players[bestindex].selected = true;
    }
    else if (tieindex != -1 && tie3 == -1) {
      players[bestindex].total = (w + (w - 1))/2.0 + players[bestindex].total;
      players[tieindex].total = (w + (w - 1))/2.0 + players[tieindex].total;
      players[bestindex].selected = true;
      players[tieindex].selected = true;
      w = w - 1;
    }
    else if (tieindex != -1 && tie3 != -1) {
      players[bestindex].total = (w + (w - 1) + (w - 2))/3.0 + players[bestindex].total;
      players[tieindex].total = (w + (w - 1) + (w - 2))/3.0 + players[tieindex].total;
      players[tie3].total = (w + (w - 1) + (w - 2))/3.0 + players[tie3].total;
      players[bestindex].selected = true;
      players[tieindex].selected = true;
      players[tie3].selected = true;
      w = w - 2;
    }
  }
  makefalse(players);
  for (double w = 12; w > 0; --w) {
    int best = 0;
    int bestindex;
    int tieindex = -1;
    int tie3 = -1;
    int q = 0;
    bool twotie = false;
    for (q = 0; q < 12; ++q) {
      if ((players[q].hr > best) && !(players[q].selected)) {
        bestindex = q;
        best = players[q].hr;
        tieindex = -1;
        tie3 = -1;
        twotie = false;
      }
      else if (players[q].hr == best && !(players[q].selected) && !twotie) {
        tieindex = q;
        twotie = true;
      }
      else if (players[q].hr == best && !(players[q].selected) && twotie) {
        tie3 = q;
      }
    }
    if (tieindex == -1 && tie3 == -1) {
      players[bestindex].total = w + players[bestindex].total;
      players[bestindex].selected = true;
    }
    else if (tieindex != -1 && tie3 == -1) {
      players[bestindex].total = (w + (w - 1))/2.0 + players[bestindex].total;
      players[tieindex].total = (w + (w - 1))/2.0 + players[tieindex].total;
      players[bestindex].selected = true;
      players[tieindex].selected = true;
      w = w - 1;
    }
    else if (tieindex != -1 && tie3 != -1) {
      players[bestindex].total = (w + (w - 1) + (w - 2))/3.0 + players[bestindex].total;
      players[tieindex].total = (w + (w - 1) + (w - 2))/3.0 + players[tieindex].total;
      players[tie3].total = (w + (w - 1) + (w - 2))/3.0 + players[tie3].total;
      players[bestindex].selected = true;
      players[tieindex].selected = true;
      players[tie3].selected = true;
      w = w - 2;
    }
  }
  makefalse(players);
  for (double w = 12; w > 0; --w) {
    int best = 0;
    int bestindex;
    int tieindex = -1;
    int tie3 = -1;
    int q = 0;
    bool twotie = false;
    for (q = 0; q < 12; ++q) {
      if ((players[q].rbi > best) && !(players[q].selected)) {
        bestindex = q;
        best = players[q].rbi;
        tieindex = -1;
        tie3 = -1;
        twotie = false;
      }
      else if ((players[q].rbi == best) && !(players[q].selected) && !(twotie)) {
        tieindex = q;
        twotie = true;
      }
      else if ((players[q].rbi) == best && !(players[q].selected) && twotie) {
        tie3 = q;
      }
    }
    if (tieindex == -1 && tie3 == -1) {
      players[bestindex].total = w + players[bestindex].total;
      players[bestindex].selected = true;
    }
    else if (tieindex != -1 && tie3 == -1) {
      players[bestindex].total = (w + (w - 1))/2.0 + players[bestindex].total;
      players[tieindex].total = (w + (w - 1))/2.0 + players[tieindex].total;
      players[bestindex].selected = true;
      players[tieindex].selected = true;
      w = w - 1;
    }
    else if (tieindex != -1 && tie3 != -1) {
      players[bestindex].total = (w + (w - 1) + (w - 2))/3.0 + players[bestindex].total;
      players[tieindex].total = (w + (w - 1) + (w - 2))/3.0 + players[tieindex].total;
      players[tie3].total = (w + (w - 1) + (w - 2))/3.0 + players[tie3].total;
      players[bestindex].selected = true;
      players[tieindex].selected = true;
      players[tie3].selected = true;
      w = w - 2;
    }
  }
  makefalse(players);
  for (double w = 12; w > 0; --w) {
    int best = 0;
    int bestindex;
    int tieindex = -1;
    int tie3 = -1;
    int q = 0;
    bool twotie = false;
    for (q = 0; q < 12; ++q) {
      if ((players[q].sb > best) && !(players[q].selected)) {
        bestindex = q;
        best = players[q].sb;
        tieindex = -1;
        tie3 = -1;
        twotie = false;
      }
      else if (players[q].sb == best && !(players[q].selected) && !twotie) {
        tieindex = q;
        twotie = true;
      }
      else if (players[q].sb == best && !(players[q].selected) && twotie) {
        tie3 = q;
      }
    }
    if (tieindex == -1 && tie3 == -1) {
      players[bestindex].total = w + players[bestindex].total;
      players[bestindex].selected = true;
    }
    else if (tieindex != -1 && tie3 == -1) {
      players[bestindex].total = (w + (w - 1))/2.0 + players[bestindex].total;
      players[tieindex].total = (w + (w - 1))/2.0 + players[tieindex].total;
      players[bestindex].selected = true;
      players[tieindex].selected = true;
      w = w - 1;
    }
    else if (tieindex != -1 && tie3 != -1) {
      players[bestindex].total = (w + (w - 1) + (w - 2))/3.0 + players[bestindex].total;
      players[tieindex].total = (w + (w - 1) + (w - 2))/3.0 + players[tieindex].total;
      players[tie3].total = (w + (w - 1) + (w - 2))/3.0 + players[tie3].total;
      players[bestindex].selected = true;
      players[tieindex].selected = true;
      players[tie3].selected = true;
      w = w - 2;
    }
  }
  makefalse(players);
  for (double w = 12; w > 0; --w) {
    double best = 0;
    int bestindex;
    int tieindex = -1;
    int tie3 = -1;
    int q = 0;
    bool twotie = false;
    for (q = 0; q < 12; ++q) {
      if ((players[q].ops > best) && !(players[q].selected)) {
        bestindex = q;
        best = players[q].ops;
        tieindex = -1;
        tie3 = -1;
        twotie = false;
      }
      else if (players[q].ops == best && !(players[q].selected) && !twotie) {
        tieindex = q;
        twotie = true;
      }
      else if (players[q].ops == best && !(players[q].selected) && twotie) {
        tie3 = q;
      }
    }
    if (tieindex == -1 && tie3 == -1) {
      players[bestindex].total = w + players[bestindex].total;
      players[bestindex].selected = true;
    }
    else if (tieindex != -1 && tie3 == -1) {
      players[bestindex].total = (w + (w - 1))/2.0 + players[bestindex].total;
      players[tieindex].total = (w + (w - 1))/2.0 + players[tieindex].total;
      players[bestindex].selected = true;
      players[tieindex].selected = true;
      w = w - 1;
    }
    else if (tieindex != -1 && tie3 != -1) {
      players[bestindex].total = (w + (w - 1) + (w - 2))/3.0 + players[bestindex].total;
      players[tieindex].total = (w + (w - 1) + (w - 2))/3.0 + players[tieindex].total;
      players[tie3].total = (w + (w - 1) + (w - 2))/3.0 + players[tie3].total;
      players[bestindex].selected = true;
      players[tieindex].selected = true;
      players[tie3].selected = true;
      w = w - 2;
    }
  }
  makefalse(players);
  for (double w = 12; w > 0; --w) {
    int best = 0;
    int bestindex;
    int tieindex = -1;
    int tie3 = -1;
    int q = 0;
    bool twotie = false;
    for (q = 0; q < 12; ++q) {
      if ((players[q].ks > best) && !(players[q].selected)) {
        bestindex = q;
        best = players[q].ks;
        tieindex = -1;
        tie3 = -1;
        twotie = false;
      }
      else if (players[q].ks == best && !(players[q].selected) && !twotie) {
        tieindex = q;
        twotie = true;
      }
      else if (players[q].ks == best && !(players[q].selected) && twotie) {
        tie3 = q;
      }
    }
    if (tieindex == -1 && tie3 == -1) {
      players[bestindex].total = w + players[bestindex].total;
      players[bestindex].selected = true;
    }
    else if (tieindex != -1 && tie3 == -1) {
      players[bestindex].total = (w + (w - 1))/2.0 + players[bestindex].total;
      players[tieindex].total = (w + (w - 1))/2.0 + players[tieindex].total;
      players[bestindex].selected = true;
      players[tieindex].selected = true;
      w = w - 1;
    }
    else if (tieindex != -1 && tie3 != -1) {
      players[bestindex].total = (w + (w - 1) + (w - 2))/3.0 + players[bestindex].total;
      players[tieindex].total = (w + (w - 1) + (w - 2))/3.0 + players[tieindex].total;
      players[tie3].total = (w + (w - 1) + (w - 2))/3.0 + players[tie3].total;
      players[bestindex].selected = true;
      players[tieindex].selected = true;
      players[tie3].selected = true;
      w = w - 2;
    }
  }
  makefalse(players);
  for (double w = 12; w > 0; --w) {
    int best = 0;
    int bestindex;
    int tieindex = -1;
    int tie3 = -1;
    int q = 0;
    bool twotie = false;
    for (q = 0; q < 12; ++q) {
      if ((players[q].wins > best) && !(players[q].selected)) {
        bestindex = q;
        best = players[q].wins;
        tieindex = -1;
        tie3 = -1;
        twotie = false;
      }
      else if ((players[q].wins == best) && !(players[q].selected) && !twotie) {
        tieindex = q;
        twotie = true;
      }
      else if ((players[q].wins == best) && !(players[q].selected) && twotie) {
        tie3 = q;
      }
    }
    if (tieindex == -1 && tie3 == -1) {
      players[bestindex].total = w + players[bestindex].total;
      players[bestindex].selected = true;
    }
    else if (tieindex != -1 && tie3 == -1) {
      players[bestindex].total = w - .5 + players[bestindex].total;
      players[tieindex].total = w - .5 + players[tieindex].total;
      players[bestindex].selected = true;
      players[tieindex].selected = true;
      w = w - 1;
    }
    else if (tieindex != -1 && tie3 != -1) {
      players[bestindex].total = ((w + (w - 1) + (w - 2))/3.0) + players[bestindex].total;
      players[tieindex].total = ((w + (w - 1) + (w - 2))/3.0) + players[tieindex].total;
      players[tie3].total = ((w + (w - 1) + (w - 2))/3.0) + players[tie3].total;
      players[bestindex].selected = true;
      players[tieindex].selected = true;
      players[tie3].selected = true;
      w = w - 2;
    }
  }
  makefalse(players);
  for (double w = 12; w > 0; --w) {
    double best = 10000;
    int bestindex;
    int tieindex = -1;
    int tie3 = -1;
    int q = 0;
    bool twotie = false;
    for (q = 0; q < 12; ++q) {
      if ((players[q].era < best) && !(players[q].selected)) {
        bestindex = q;
        best = players[q].era;
        tieindex = -1;
        tie3 = -1;
        twotie = false;
      }
      else if (players[q].era == best && !(players[q].selected) && !twotie) {
        tieindex = q;
        twotie = true;
      }
      else if (players[q].era == best && !(players[q].selected) && twotie) {
        tie3 = q;
      }
    }
    if (tieindex == -1 && tie3 == -1) {
      players[bestindex].total = w + players[bestindex].total;
      players[bestindex].selected = true;
    }
    else if (tieindex != -1 && tie3 == -1) {
      players[bestindex].total = (w + (w - 1))/2.0 + players[bestindex].total;
      players[tieindex].total = (w + (w - 1))/2.0 + players[tieindex].total;
      players[bestindex].selected = true;
      players[tieindex].selected = true;
      w = w - 1;
    }
    else if (tieindex != -1 && tie3 != -1) {
      players[bestindex].total = (w + (w - 1) + (w - 2))/3.0 + players[bestindex].total;
      players[tieindex].total = (w + (w - 1) + (w - 2))/3.0 + players[tieindex].total;
      players[tie3].total = (w + (w - 1) + (w - 2))/3.0 + players[tie3].total;
      players[bestindex].selected = true;
      players[tieindex].selected = true;
      players[tie3].selected = true;
      w = w - 2;
    }
  }
  makefalse(players);
  for (double w = 12; w > 0; --w) {
    double best = 1000;
    int bestindex;
    int tieindex = -1;
    int tie3 = -1;
    int q = 0;
    bool twotie = false;
    for (q = 0; q < 12; ++q) {
      if ((players[q].whip < best) && !(players[q].selected)) {
        bestindex = q;
        best = players[q].whip;
        tieindex = -1;
        tie3 = -1;
        twotie = false;
      }
      else if (players[q].whip == best && !(players[q].selected) && !twotie) {
        tieindex = q;
        twotie = true;
      }
      else if (players[q].whip == best && !(players[q].selected) && twotie) {
        tie3 = q;
      }
    }
    if (tieindex == -1 && tie3 == -1) {
      players[bestindex].total = w + players[bestindex].total;
      players[bestindex].selected = true;
    }
    else if (tieindex != -1 && tie3 == -1) {
      players[bestindex].total = (w + (w - 1))/2.0 + players[bestindex].total;
      players[tieindex].total = (w + (w - 1))/2.0 + players[tieindex].total;
      players[bestindex].selected = true;
      players[tieindex].selected = true;
      w = w - 1;
    }
    else if (tieindex != -1 && tie3 != -1) {
      players[bestindex].total = (w + (w - 1) + (w - 2))/3.0 + players[bestindex].total;
      players[tieindex].total = (w + (w - 1) + (w - 2))/3.0 + players[tieindex].total;
      players[tie3].total = (w + (w - 1) + (w - 2))/3.0 + players[tie3].total;
      players[bestindex].selected = true;
      players[tieindex].selected = true;
      players[tie3].selected = true;
      w = w - 2;
    }
  }
  makefalse(players);
  for (double w = 12; w > 0; --w) {
    int best = 0;
    int bestindex;
    int tieindex = -1;
    int tie3 = -1;
    int q = 0;
    bool twotie = false;
    for (q = 0; q < 12; ++q) {
      if ((players[q].saves > best) && !(players[q].selected)) {
        bestindex = q;
        best = players[q].saves;
        tieindex = -1;
        tie3 = -1;
        twotie = false;
      }
      else if (players[q].saves == best && !(players[q].selected) && !twotie) {
        tieindex = q;
        twotie = true;
      }
      else if (players[q].saves == best && !(players[q].selected) && twotie) {
        tie3 = q;
      }
    }
    if (tieindex == -1 && tie3 == -1) {
      players[bestindex].total = w + players[bestindex].total;
      players[bestindex].selected = true;
    }
    else if (tieindex != -1 && tie3 == -1) {
      players[bestindex].total = (w + (w - 1))/2.0 + players[bestindex].total;
      players[tieindex].total = (w + (w - 1))/2.0 + players[tieindex].total;
      players[bestindex].selected = true;
      players[tieindex].selected = true;
      w = w - 1;
    }
    else if (tieindex != -1 && tie3 != -1) {
      players[bestindex].total = (w + (w - 1) + (w - 2))/3.0 + players[bestindex].total;
      players[tieindex].total = (w + (w - 1) + (w - 2))/3.0 + players[tieindex].total;
      players[tie3].total = (w + (w - 1) + (w - 2))/3.0 + players[tie3].total;
      players[bestindex].selected = true;
      players[tieindex].selected = true;
      players[tie3].selected = true;
      w = w - 2;
    }
  }
  makefalse(players);
  member end;
  vector <member> final;
  double top;
  for (int XY = 0; XY < 12; ++XY) {
    top = 0;
    double bestindex = -1;
    for (int X = 0; X < 12; ++X) {
      if ((players[X].total > top) && !(players[X].selected)) {
        bestindex = X;
        top = players[X].total;
      }
    }
    players[bestindex].selected = true;
    end.name = players[bestindex].name;
    end.total = players[bestindex].total;
    final.push_back(end);
  }
  makefalse(players);
  vector <member> sortedwins;
  for (int XY = 0; XY < 12; ++XY) {
    top = 0;
    double bestindex = -1;
    for (int X = 0; X < 12; ++X) {
      if ((players[X].percentage > top) && !(players[X].selected)) {
        bestindex = X;
        top = players[X].percentage;
      }
    }
    players[bestindex].selected = true;
    players[bestindex].actualstanding = XY + 1;
  }
  //
  // for (int x = 0; x < 12; ++x) {
  //   string name = final[x].name;
  //   for (int y = 0; y < 12; ++y) {
  //     if (players[y].name == final[x].name) {
  //       final[x].actualstanding = players[y].actualstanding;
  //     }
  //   }
  // }

  for (int x = 0; x < 12; ++x) {
    addSpaces(final[x].name);
  }

  cout << "Standings" << endl;
  int count = 1;
  for (int W = 0; W < 12; ++W) {
    cout << count << ". ";
    cout << final[W].name << " ";
    cout << final[W].total << endl;
    count++;
  }

}
