//OpenCv.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Math.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <algorithm>

// Trabalho 1 — Filtros Espaciais e Nitidez

// 1. Fácil — Negativo fotográfico. Inverter a intensidade de cada canal, limitando os
// resultados ao intervalo válido.


	// 2. Intermédio — Filtro de média.Implementar uma convolução com janela quadrada
	// e permitir alterar o tamanho da janela.

	void filtroMediaManual/* Determina a função*/ (const cv::Mat& imgEntrada, /* Recebe a imagem*/ cv::Mat& imgSaída/*Recebe a imagem de saida, para guardar o resultado*/, int tamanhoJanela/*Tamanho da janela*/) {
		
		// Tamanho da janela impar, senão soma 1
		if (tamanhoJanela % 2 == 0) tamanhoJanela++;
		
		// Calcula quantos pixeis a janela tem, do centro para os lados da janela
		int raio = tamanhoJanela / 2;

		//Calcula o nº total de pixeis da janela
		int numPixeisJanela = tamanhoJanela * tamanhoJanela;

		// Cria uma cópia da imagem original na imagem de saída
		imgSaida = imgEntrada.clone();

		// Guarda a altura da imagem
		int linhas = imgEntrada.rows;

		// Guarda a largura da imagem
		int colunas = imgEntrada.cols;

		// Verifica se a imagem tem 1 canal ou 3 canais
		int canais = imgEntrada.channels();

		// Ciclo para percorrer a imagem
		for (int y = 0; y < linhas; y++) { //Por linha
			for (int x = 0; x < colunas; x++) { //Por coluna
				
				if (canais == 3) {// Se for imagem colorida
					long somaB = 0, somaG = 0, somaR = 0; //Começo da contagem para somar a intensidade das cores

					// Ciclo para percorrer as linhas
					for (int ky = -raio; ky <= raio; ky++) {

						// Ciclo para percorrer as colunas
						for (int kx = -raio; kx <= raio; kx++) {
							// Ler os limites horizontais
							int px = std::clamp(x + kx, 0, colunas - 1);

							// Ler os limites verticais
							int py = std::clamp(y + ky, 0, linhas - 1);

							// Ler o valor das 3 cores
							cv::Vec3b pixel = imgEntrada.at<cv::Vec3b>(py, px);
							somaB += pixel[0]; // Soma o canal Azul
							somaG += pixel[1]; // Soma o canal Verde
							somaR += pixel[2]; // Soma o canal Vermelho
						}
					}

					// Divide a soma do Azul pelo nº de pixeis
					imgSaída.at<cv::Vec3b>(y, x)[0] = static_cast<uchar>(somaB / numPixeisJanela);
					// Divide a soma do Verde pelo nº de pixeis
					imgSaída.at<cv::Vec3b>(y, x)[1] = static_cast<uchar>(somaG / numPixeisJanela);
					// Divide a soma do Vermelho pelo nº de pixeis
					imgSaida.at<cv::Vec3b>(y, x)[2] = static_cast<uchar>(somaR / numPixeisJanela);
				}
				else if (canais == 1) { // Se a imagem for cinzenta
					long soma = 0; // Iniciar a contagem para a soma das intensidades da janela

					for (int ky = -raio; ky <= raio; ky++) { // Ciclo na vertical
						for (int kx = -raio; kx <= raio; kx++) { // Ciclo no horizontal
							int px = std::clamp(x + kx, 0, colunas - 1);
							int py = std::clamp(y + ky, 0, linhas - 1); 

							// Soma o valor de cinzento
							soma += imgEntrada.at<uchar>(py, px); 
						}
					}
					// Divide a soma pelo nº total de pixeis na janela e atribui ao pixel de saída
					imgSaida.at<uchar>(y, x) = static_cast<uchar>(soma / numPixeisJanela);
				}
			}
		}

	// 3. Intermédio — Filtro Gaussiano. Construir o núcleo Gaussiano a partir do tamanho
	// da janela e do desvio - padrão e aplicá - lo por convolução.

	/*Mat gauss;

	Mat suave;
	GaussianBlur(img, suave, Size(5, 5), 1.2);

	imshow("Gaussiano", gauss);

	*/

// 4. Difícil — Máscara de nitidez(unsharp masking).Suavizar a imagem, calcular
// a diferença para a original e reforçar os detalhes com um factor configurável.



// 5. Difícil — Realce por Laplaciano.Implementar o operador Laplaciano e combiná - lo
// com a imagem original para realçar transições de intensidade.



