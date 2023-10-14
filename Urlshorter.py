import hashlib

url_mapping = {}

def shorten_url(long_url):
    # Generate a unique short URL from the long URL
    short_url = hashlib.md5(long_url.encode()).hexdigest()[:8]
    url_mapping[short_url] = long_url
    return short_url

def expand_url(short_url):
    # Retrieve the long URL from the short URL
    long_url = url_mapping.get(short_url)
    return long_url

def main():
    while True:
        print("\nURL Shortener")
        print("1. Shorten URL")
        print("2. Expand URL")
        print("3. Exit")
        choice = input("Select an option: ")

        if choice == '1':
            long_url = input("Enter the long URL to shorten: ")
            short_url = shorten_url(long_url)
            print(f"Shortened URL: {short_url}")

        elif choice == '2':
            short_url = input("Enter the short URL to expand: ")
            long_url = expand_url(short_url) 
            if long_url:
                print(f"Expanded URL: {long_url}")
            else:
                print("Short URL not found.")

        elif choice == '3':
            break

        else:
            print("Invalid choice. Please select a valid option.")

if __name__ == "__main__":
    main()

