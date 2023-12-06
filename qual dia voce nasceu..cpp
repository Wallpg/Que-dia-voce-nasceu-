#include <stdio.h>
#include <time.h>
#include <locale.h>

int main() {
	setlocale( LC_ALL,"Portuguese");
    int diaAtual, mesAtual, anoAtual;
    int diaNascimento, mesNascimento, anoNascimento;

    printf("\nDigite o dia, mês e ano atuais:\n");
    scanf("%d %d %d", &diaAtual, &mesAtual, &anoAtual);

    printf("Digite o dia, mês e ano do seu nascimento:\n");
    scanf("%d %d %d", &diaNascimento, &mesNascimento, &anoNascimento);

    struct tm dataNascimento = {0};
    dataNascimento.tm_year = anoNascimento - 1900;
    dataNascimento.tm_mon = mesNascimento - 1;
    dataNascimento.tm_mday = diaNascimento;

    struct tm dataAtual = {0};
    dataAtual.tm_year = anoAtual - 1900;
    dataAtual.tm_mon = mesAtual - 1;
    dataAtual.tm_mday = diaAtual;

    time_t tempoNascimento = mktime(&dataNascimento);
    time_t tempoAtual = mktime(&dataAtual);

    double diferenca = difftime(tempoAtual, tempoNascimento);
    int dias = diferenca / (60 * 60 * 24);

    printf("\nVocê tem %d dias de vida.\n", dias);

    // Cálculo da idade em anos, meses e dias
    int anos = dias / 365;
    int diasRestantes = dias % 365;
    int meses = diasRestantes / 30;
    int diasFinais = diasRestantes % 30;

    printf("Isso equivale a %d anos, %d meses e %d dias.\n", anos, meses, diasFinais);

    // Cálculo do dia da semana do nascimento
    const char* diasDaSemana[] = {"Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado"};
    struct tm* tm_info = localtime(&tempoNascimento);
    printf("Você nasceu em um(a) %s.\n", diasDaSemana[tm_info->tm_wday]);

    return 0;
}
