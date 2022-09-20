using System;
using System.IO;
using System.Windows;
using System.Windows.Media.Imaging;

namespace w02
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    
    public partial class MainWindow : Window
	{
		string[] resFiles;
		readonly string resDir = "Images";
		public string[] GetImageFiles()
		{
			resFiles = Directory.GetFiles(resDir);

			return resFiles;
		}

        public Tuple<string,string> NextEntry()
        {
            Random rng = new Random();
			
            string path = resFiles[rng.Next(resFiles.Length)];
            string text = path.Substring(resDir.Length + 1)    // Remove "Images/"
                              .Split('.')[0]                    // Remove ".png"
                              .Replace('_', ' ');

			return new Tuple<string, string>(path, text);
        }

		public void DisplayNewEntry()
		{
			Tuple<string, string> entry = NextEntry();

			image.Source = new BitmapImage(new Uri(entry.Item1, UriKind.Relative));

			textbox.Content = entry.Item2;
		}
        
        private void changeButton_Click(object sender, RoutedEventArgs e)
        {
			DisplayNewEntry();
		}

		public MainWindow()
		{
			InitializeComponent();
			GetImageFiles();
			DisplayNewEntry();
		}
	}
}
