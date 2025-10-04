const int Player_1 = 0;
const int Player_2 = 1;
const int Go_signal = 2;
const int buzzerPin = 3;

int scoreP1 = 0;
int scoreP2 = 0;
int roundCount = 0;
bool gameStarted = false;

void setup() {
  pinMode(Player_1, INPUT);
  pinMode(Player_2, INPUT);
  pinMode(Go_signal, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (roundCount < 10 && !gameStarted) {
    delay(random(1000, 5000));
    digitalWrite(Go_signal, HIGH);
    gameStarted = true;
  }

  if (gameStarted) {
    if (digitalRead(Player_1) == HIGH) {
      scoreP1++;
      announceRoundWinner("Player 1");
    } else if (digitalRead(Player_2) == HIGH) {
      scoreP2++;
      announceRoundWinner("Player 2");
    }
  }

  if (roundCount >= 10) {
    announceFinalWinner();
    while (true); // Stop the game
  }
}

void announceRoundWinner(String winner) {
  Serial.println("Round " + String(roundCount + 1) + ": " + winner + " wins!");
  digitalWrite(buzzerPin, HIGH);
  delay(300);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(Go_signal, LOW);
  roundCount++;
  gameStarted = false;
}

void announceFinalWinner() {
  Serial.println("🏁 Game Over!");
  Serial.println("Player 1 Score: " + String(scoreP1));
  Serial.println("Player 2 Score: " + String(scoreP2));

  if (scoreP1 > scoreP2) {
    Serial.println("🎉 Player 1 is the Champion!");
  } else if (scoreP2 > scoreP1) {
    Serial.println("🎉 Player 2 is the Champion!");
  } else {
    Serial.println("🤝 It's a Tie!");
  }
}
