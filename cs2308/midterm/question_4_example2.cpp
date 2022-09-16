int main(int argc, char** argv)
{
    // initialize the message string (C-string)
    char message[] = "Hello. This is a short message.";
    char *ptr = &message[0]; // set ptr to point to address of first character of message

    // loop that continues until end of message string is reached or until ptr points to a period
    while(*ptr != '\0' && *ptr != '.'){

        cout << *ptr; // display the character pointed by ptr
        ptr++; // advance ptr to the next character
    }

    return 0;
}
