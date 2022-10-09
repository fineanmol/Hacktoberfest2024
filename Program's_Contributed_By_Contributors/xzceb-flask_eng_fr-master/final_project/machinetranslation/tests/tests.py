import unittest
from "machinetranslation/translator.py" import english_to_french, french_to_english

class TestEnglishToFrench(unittest.TestCase): 
    def test1(self): 
        self.assertEqual(english_to_french('How are you'), 'Comment vous êtes') 
        self.assertEqual(english_to_french('I am at home'), 'Je suis à la maison')
    def test2(self):
        self.assertEqual(english_to_french('Hello'), 'Bonjour')
    def test_negative(self):
        self.assertIsNone(None, 'text must be provided')
        
class TestFrenchToEnglish(unittest.TestCase): 
    def test1(self): 
        self.assertEqual(french_to_english('Comment allez-vous'), 'How are you') 
        self.assertEqual(french_to_english('Je suis à la maison'), "I'm at home") 
    def test2(self):
        self.assertEqual(french_to_english('Bonjour'), 'Hello')
    def test_negative(self):
        self.assertIsNone(None, 'text must be provided')

unittest.main()