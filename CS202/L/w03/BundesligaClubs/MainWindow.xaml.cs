using System;
using System.IO;
using System.Windows;
using System.Windows.Media.Imaging;

namespace BundesligaClubs
{
	/// <summary>
	/// Interaction logic for MainWindow.xaml
	/// </summary>
	public partial class MainWindow : Window
	{
		string[] resFiles;
		readonly string resDir = $"{AppDomain.CurrentDomain.BaseDirectory}res";

		public string[] GetImageFiles()
		{
			resFiles = Directory.GetFiles(resDir);

			return resFiles;
		}

		class Entry
		{
			public string Logo { get; set; }
			public string Name { get; set; }
		}

		static Entry _entry = new Entry();

        public Tuple<string,string> NextEntry()
        {
            Random rng = new Random();
			
            string path = resFiles[rng.Next(resFiles.Length)];
            string text = path.Substring(resDir.Length + 1)    // Remove ".../res/"
                              .Split('.')[0]                    // Remove ".png"
                              .Replace('_', ' ');

			return new Tuple<string, string>(path, text);
        }

		public void DisplayNewEntry()
		{
			Tuple<string, string> entry = NextEntry();

			_entry = new Entry
			{
				Logo = entry.Item1,
				Name = entry.Item2
			};
		}
        
        private void changeButton_Click(object sender, RoutedEventArgs e)
        {
			DisplayNewEntry();
			this.DataContext = _entry;
		}

		public MainWindow()
		{
			InitializeComponent();
		}

		private void Window_Loaded(object sender, RoutedEventArgs e)
		{
			GetImageFiles();
			DisplayNewEntry();
			this.DataContext = _entry;
		}
	}
}
