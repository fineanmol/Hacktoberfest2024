def main(*args):
    try:
        import ProgramFiles.Blackjack.blackjack
        ProgramFiles.Blackjack.blackjack.main()
    except Exception as EXP:
        from ProgramFiles.errorHandler import messagebox
        print(EXP)
        messagebox.showerror(None, None, None, True, "APP_NOT_FOUND_ERROR")
        