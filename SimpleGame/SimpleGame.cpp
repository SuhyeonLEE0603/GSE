/*
Copyright 2022 Lee Taek Hee (Tech University of Korea)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include <iostream>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"
#include "timeapi.h"

#include "GSEGlobal.h"
#include "GSEGame.h"
#include "GSEUserInterface.h"

GSEGame* g_game = NULL;
GSEUserInterface* g_userInterface = NULL;
DWORD g_startTime = 0;
DWORD g_prevTime = 0;

void RenderScene(void)
{
	DWORD elapsedTime = 0;
	DWORD currentTime = timeGetTime();
	if (g_prevTime == 0) {
		elapsedTime = currentTime - g_startTime;
	}
	else {
		elapsedTime = currentTime - g_prevTime;
	}
	g_prevTime = currentTime;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
	timeGetTime();
	
	// elapsed time (ms -> s)
	float elapsedTimeinSec = (float)elapsedTime / 1000.f;

	// send key inputs
	g_game->KeyInput(g_userInterface);

	// Renderer Test
	g_game->DrawAll(elapsedTimeinSec);

	glutSwapBuffers();
}

void Idle(void)
{
	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{
	RenderScene();
}

void KeyInput(unsigned char key, int x, int y)
{
	RenderScene();
}

void SpecialKeyDownInput(int id, int x, int y)
{
	unsigned char key = '~';
	g_userInterface->KeyDown(key, id);
}

void SpecialKeyUpInput(int id, int x, int y)
{
	unsigned char key = '~';
	g_userInterface->KeyUp(key, id);
}

int main(int argc, char **argv)
{
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);		// 디스플레이에 depth 버퍼, 더블 더퍼링 RGBA 사용
	glutInitWindowPosition(0, 0);									// 메인 윈도우 (0, 0) 좌표로 설정
	glutInitWindowSize(500, 500);									// 메인 윈도우 사이즈
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}

	// Initialize Renderer
	g_userInterface = new GSEUserInterface();
	g_game = new GSEGame(500, 500);

	glutDisplayFunc(RenderScene);			// 콜백 함수들, 함수 포인터를 넘겨줌
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyDownInput);
	glutSpecialUpFunc(SpecialKeyUpInput);

	g_startTime = timeGetTime();
	glutMainLoop();

	delete g_game;

    return 0;
}

