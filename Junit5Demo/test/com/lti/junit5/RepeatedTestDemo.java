package com.lti.junit5;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.RepeatedTest;
import org.junit.jupiter.api.Test;

class RepeatedTestDemo {


@RepeatedTest(5)
void simpleRepeatedTest()
{
	assertTrue(0<5);
}

@RepeatedTest(value=5,name="{displayName}= {currentRepetition}/{totalRepetitions}")
@DisplayName("Repetator Test No ")
void simpleRepeatedTest1()
{
	assertTrue(0<5);
}


}
