from pytube import YouTube
import os

def download_youtube_video(url, save_path='.'):
    try:
        # Create a YouTube object
        yt = YouTube(url)
        
        # Get the highest resolution stream
        ys = yt.streams.get_highest_resolution()
        
        # Download the video
        print(f"Downloading {yt.title}...")
        ys.download(save_path)
        print(f"Downloaded {yt.title} successfully.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    # URL of the YouTube video to be downloaded
    video_url = input("Enter video URL: ")
    
    # Directory where the video will be saved
    save_directory = input("Enter the directory to save the video (leave blank for current directory): ").strip()
    
    # Use the current directory if no input is provided
    if not save_directory:
        save_directory = '.'
    
    # Check if the directory exists, create if it doesn't
    if not os.path.exists(save_directory):
        os.makedirs(save_directory)
    
    # Call the function to download the video
    download_youtube_video(video_url, save_directory)
