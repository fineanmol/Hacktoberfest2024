import argparse
from translate import Translator


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--from_lang", help="Language to translate from.", type=str)
    parser.add_argument(
        "--to_lang", help="Language to translate to. (defaults to English)",
        type=str)
    text = input("Enter text to translate: ")
    args = parser.parse_args()
    if args.from_lang:
        translator = Translator(
            to_lang=args.to_lang if args.to_lang else "English",
            from_lang=args.from_lang
        )
    else:
        translator = Translator(
            to_lang=args.to_lang if args.to_lang else "English")
    try:
        translation = translator.translate(text)
    except Exception:
        print("Translation Error. Returning...")
        return None
    print(translation)


if __name__ == "__main__":
    main()
