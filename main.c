#include <stdio.h>

int simulate_double_escalator(int N, int people[][2]) {
    int last_stop = 0;  // Variável para armazenar o último momento em que a escada parou
    int direction = -1;  // Direção inicial da escada, -1 indica que ainda não foi definida

    for (int i = 0; i < N; i++) {
        int time = people[i][0];
        int desired_direction = people[i][1];

        if (direction == -1 || direction == desired_direction) {
            // Se a escada está parada ou se está indo na direção desejada pela pessoa, ela entra imediatamente
            direction = desired_direction;
            last_stop = time > last_stop ? time : last_stop;  // A escada começa a se mover no momento em que a pessoa entra
        } else {
            // Se a escada está indo na direção oposta, esperamos até que ela pare
            last_stop += 10;  // A escada leva 10 segundos para se mover de um lado para o outro
            direction = desired_direction;
        }
    }

    return last_stop + 10;  // Adiciona 10 segundos para representar o momento em que a escada parou pela última vez
}

int main() {
    int N;
    scanf("%d", &N);

    int people[N][2];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &people[i][0], &people[i][1]);
    }

    // Chamada da função e impressão do resultado
    int result = simulate_double_escalator(N, people);
    printf("%d\n", result);

    return 0;
}