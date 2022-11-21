using Contract;
using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Text;
using System.Windows;
using Microsoft.WindowsAPICodePack.Dialogs;

namespace FinalProject
{
	public partial class MainWindow : Window
	{
		public ObservableCollection<object> _originals = new ObservableCollection<object>();
		public ObservableCollection<object> _previews = new ObservableCollection<object>();
		public ObservableCollection<object> _availableRules = new ObservableCollection<object>();
		public ObservableCollection<object> _selectedRules = new ObservableCollection<object>();

		RuleFactory f = new RuleFactory();
		dynamic selectedRuleFromAvailable = null;
		dynamic selectedRuleFromPreview = null;
		
		string rulePresetFileFullPath = "";
		string destinationFolderFullPath = "";

		struct FileEntryInfo
        {
			public string FullPath { get; set; }
			public string FileName { get; set; }
			public int ItemIndex { get; set; }
        }

        public MainWindow()
		{
			InitializeComponent();
		}

		private void Window_Loaded(object sender, RoutedEventArgs e)
		{
			filesListView.ItemsSource = _originals;
			previewListView.ItemsSource = _previews;

			// Load .dll file to show available rules in menu
			DLLReader dllReader = new DLLReader();

			foreach (var rule in dllReader.GetRuleDict())
			{
				var item = new
				{
					RuleName = rule.Value.Name,
					RuleConfig = rule.Value.Config
				};

				_availableRules.Add(item);
			}

			ruleSelectListView.ItemsSource = _availableRules;
			rulePreviewListView.ItemsSource = _selectedRules;
		}



		// ========================================
		// =============== Utilities ==============
		// ========================================
		
		// Update file preview list (intergrated inside UpdateFactory)
		private void UpdateFilePreviewList(bool forced = false)
		{
			if (_originals.Count > 0 || forced)
			{
				_previews.Clear();

                int newIndex = 0;
				foreach (dynamic item in _originals)
				{
					//item.ItemIndex = newIndex++;
                    _previews.Add(item);
                }
            }
		}

		
		// Update factory's RuleString with elements in _selectedRules
		private void UpdateFactory()
		{
			List<IRule> newRuleList = new List<IRule>();

			foreach (dynamic item in _selectedRules)
			{
				StringBuilder sb = new StringBuilder();
				sb.Append(item.RuleName)
					.Append(" ")
					.Append(item.RuleConfig);

				IRule newRule = f.StringToIRuleConverter(sb.ToString());
				newRuleList.Add(newRule);
			}

			f.RuleList = newRuleList;

			// Update converter and filePreviewList
			var converter = FindResource("converter") as RawToRenamedConverter;
			converter!.Factory = f;

			UpdateFilePreviewList();
		}
		
		
		private void LoadRulePreset(String fileFullPath)
		{
			var info = new FileInfo(fileFullPath);

			List<IRule> newRuleList = PresetProcessor.ReadPresetFile(fileFullPath, f, out bool success);

			if (success)
			{
				f.RuleList = newRuleList;
				rulePresetFileFullPath = fileFullPath;

				// Display the rule file name to TextBox
				ruleFileName.Text = info.Name;

				//Update rule preview list
				_selectedRules.Clear();

				foreach (var r in f.RuleList)
				{
					if (r == null) continue;

					var item = new
					{
						RuleName = r.Name,
						RuleConfig = r.Config
					};
					_selectedRules.Add(item);
				}
				rulePreviewListView.ItemsSource = _selectedRules;

				UpdateFactory();
			}
		}


		
		// ====================================
		// ========== File selection ==========
		// ====================================

		
		// Add file to be renamed
		private void addFileButton_Click(object sender, RoutedEventArgs e)
		{
			var dialog = new OpenFileDialog();

			if (dialog.ShowDialog() == true)
			{
				// Skip if already added
				bool duplicated = false;
				foreach (dynamic item in _originals)
				{
					if (item.FullPath == dialog.FileName) { duplicated = true; break; }
				}
				if (duplicated) return;

				var info = new FileInfo(dialog.FileName);

				var rawItem = new FileEntryInfo
				{
					FullPath = dialog.FileName,
					FileName = info.Name,
					ItemIndex = _originals.Count
				};

				_originals.Add(rawItem);
				_previews.Add(rawItem);
			}
		}
		
		
		// Remove added file from list
		private void removeFileButton_Click(object sender, RoutedEventArgs e)
		{
			if (filesListView.SelectedIndex != -1)
			{
				_originals.RemoveAt(filesListView.SelectedIndex);

				UpdateFilePreviewList(true);
			}
		}

		
		// Add all files inside a folder
		private void addFolderButton_Click(object sender, RoutedEventArgs e)
		{
			CommonOpenFileDialog dialog = new CommonOpenFileDialog();

			dialog.InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);
			dialog.IsFolderPicker = true;

			if (dialog.ShowDialog() == CommonFileDialogResult.Ok)
			{
				// Add all files in the folder
				var files = Directory.GetFiles(dialog.FileName);

				foreach (var file in files)
				{
					// Skip if already added
					bool duplicated = false;
					foreach (dynamic item in _originals) { if (item.FullPath == file) { duplicated = true; break; } }
					if (duplicated) continue;

					var info = new FileInfo(file);

					var rawItem = new FileEntryInfo
					{
						FullPath = file,
						FileName = info.Name,
                        ItemIndex = _originals.Count
                    };

					_originals.Add(rawItem);
					_previews.Add(rawItem);
				}
			}
		}



		// ===================================
		// ========== Rules configs ==========
		// ===================================

		// Select preset file
		private void selectRulePresetButton_Click(object sender, RoutedEventArgs e)
		{
			var dialog = new OpenFileDialog
			{
                Title = "Open Rule Preset File...",
                Filter = "Rule Files (*.txt; *.json)|*.txt;*.json|All files (*.*)|*.*"
        	};

			if (dialog.ShowDialog() == true)
			{
                LoadRulePreset(dialog.FileName);
			}
		}


		// Selection in available rule list changed
		private void ruleSelectListView_SelectionChanged(object sender, System.Windows.Controls.SelectionChangedEventArgs e)
		{
			// Update ruleConfigTextBox's text
			selectedRuleFromAvailable = ruleSelectListView.SelectedItem;
			ruleConfigTextBox.Text = selectedRuleFromAvailable.RuleConfig;
		}

		
		// Add selected rule to rule preview list
		private void addRuleButton_Click(object sender, RoutedEventArgs e)
		{
			if (selectedRuleFromAvailable == null) { return; }
			
			_selectedRules.Add( new { RuleName = selectedRuleFromAvailable.RuleName,
									  RuleConfig = ruleConfigTextBox.Text } );
			
			UpdateFactory();
		}

		
		// Text inside ruleConfigTextBox was modified
		private void ruleConfigTextBox_TextChanged(object sender, System.Windows.Controls.TextChangedEventArgs e)
		{
			return;
		}

		
		// Remove selected rule from rule preview list
		private void rulePreviewListView_SelectionChanged(object sender, System.Windows.Controls.SelectionChangedEventArgs e)
		{
			return;
		}

		
		// Move selected rule in rule preview list up
		private void moveRuleUpButton_Click(object sender, RoutedEventArgs e)
		{
			if (rulePreviewListView.SelectedItem == null) { return; }

			int index = rulePreviewListView.SelectedIndex;
			if (index == 0) { return; }
			else
			{
				var temp = _selectedRules[index - 1];
				_selectedRules[index - 1] = _selectedRules[index];
				_selectedRules[index] = temp;

				rulePreviewListView.ItemsSource = _selectedRules;
				UpdateFactory();
			}
		}

		
		// Move selected rule in rule preview list down
		private void moveRuleDownButton_Click(object sender, RoutedEventArgs e)
		{
			if (rulePreviewListView.SelectedItem == null) { return; }

			int index = rulePreviewListView.SelectedIndex;
			if (index == _selectedRules.Count - 1) { return; }
			else
			{
				var temp = _selectedRules[index + 1];
				_selectedRules[index + 1] = _selectedRules[index];
				_selectedRules[index] = temp;

				rulePreviewListView.ItemsSource = _selectedRules;
				UpdateFactory();
			}
		}

		// Save the current list of rules in _selectedRules to a file
		private void saveRulePresetButton_Click(object sender, RoutedEventArgs e)
		{
			var dialog = new SaveFileDialog
			{
				Title = "Save Rule Preset File...",
				Filter = "Raw Preset File (*.txt)|*.txt|JSON Preset File (*.json)|*.json"
			};

			// If a preset file has already been loaded before, use its name as default file name for saving.
			if (ruleFileName.Text != "")
			{
				dialog.FileName = ruleFileName.Text;
			}

            if (dialog.ShowDialog() == true)
            {
                bool success = PresetProcessor.WritePresetFile(dialog, f);

				if (success)
				{
					MessageBox.Show($"Successfully saved preset to path:\n{dialog.FileName}", "Success");
				}
            }
            return;
		}


		// Open dialog to edit rule config
		private void editRulePreviewItemContextMenu_Click(object sender, RoutedEventArgs e)
		{
			int index = rulePreviewListView.SelectedIndex;
			IRule selection = f.RuleList[index];

			var screen = new EditRuleWindow(selection);

			if (screen.ShowDialog() == true)
			{
				_selectedRules[index] = new
				{
					RuleName = screen.ReturnData.Name,
					RuleConfig = screen.ReturnData.Config
				};

				rulePreviewListView.ItemsSource = _selectedRules;
				UpdateFactory();
			}
		}

		
		// Remove selected rule from rule preview list
		private void deleteRulePreviewItemContextMenu_Click(object sender, RoutedEventArgs e)
		{
			if (rulePreviewListView.SelectedItem == null) { return; }

			int index = rulePreviewListView.SelectedIndex;
			_selectedRules.RemoveAt(index);
			
			rulePreviewListView.ItemsSource = _selectedRules;
			UpdateFactory();
		}



		// ========================================
		// ========== Renaming execution ==========
		// ========================================
		
		// Open dialog to select a destination folder to save renamed file to
		private void selectDestinationFolderButton_Click(object sender, RoutedEventArgs e)
		{
			CommonOpenFileDialog dialog = new CommonOpenFileDialog();

			dialog.InitialDirectory = "C:";
			dialog.IsFolderPicker = true;

			if (dialog.ShowDialog() == CommonFileDialogResult.Ok)
			{
				destinationFolderFullPath = dialog.FileName;
				destinationFolderPathTextBox.Text = destinationFolderFullPath;
			}
		}

		
		// Text inside destinationFolderPathTextBox was modified
		private void destinationFolderPathTextBox_TextChanged(object sender, System.Windows.Controls.TextChangedEventArgs e)
		{
			destinationFolderFullPath = destinationFolderPathTextBox.Text;
		}

		
		// Start renaming
		private void renameButton_Click(object sender, RoutedEventArgs e)
		{
			List<string> errorFiles = new List<string>();
			
			foreach (dynamic item in _originals)
			{
				f.FileName = item.FileName;
				f.FileIndex = item.ItemIndex;

				var info = new FileInfo(item.FullPath);
				var folder = info.Directory;
				var newPath = "";

				// If moveToAnotherFolderCheckBox is checked, create a subdirectory called "renamed" and copy the files to it
				if (moveToAnotherFolderCheckBox.IsChecked == true)
				{
					if (destinationFolderFullPath == "")
					{
						MessageBox.Show("Please select a folder to move the renamed files to.");
						return;
					}

					// If folder exists, set it as the destination folder
					try
					{
						newPath = $"{destinationFolderFullPath}\\{f.Parse()}";
						File.Copy(item.FullPath, newPath);
					}
					// Else, create it
					catch
					{
						folder = Directory.CreateDirectory(destinationFolderFullPath);
						newPath = $"{folder}\\{f.Parse()}";
					}
				}
				else
				{
					newPath = $"{folder}\\{f.Parse()}";
					File.Move(item.FullPath, newPath);
				}

				// If catch error while copying file, save the file's name to a string to print out to a MessageBox
				try
				{
					File.Copy(item.FullPath, newPath);
				}
				catch
				{
					errorFiles.Add(item.FileName);
					continue;
				}

				if (errorFiles.Count > 0)
				{
					string errorFilesString = "";
					foreach (string file in errorFiles)
					{
						errorFilesString += $"{file}\n";
					}
					MessageBox.Show($"Failed to move the following files to the destination folder:\n{errorFilesString}");
				}
			}

			MessageBox.Show($"Renamed {_originals.Count - errorFiles.Count} files");
		}

		private void loadProjectButton_Click(object sender, RoutedEventArgs e)
		{
			// Open dialog to select a preset file
			var dialog = new OpenFileDialog { InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments) };
			
			if (dialog.ShowDialog() == true)
			{
				string fileName = dialog.FileName;
				if (fileName == null || fileName == "") { MessageBox.Show("Please select a project file."); return; };
				
				List<String> lines = new List<String>();
				
				try
				{
					using (StreamReader sr = new StreamReader(fileName))
					{
						string line;
						while ((line = sr.ReadLine()) != null)
						{
							lines.Add(line);
						}
					}
				}
				catch
				{
					MessageBox.Show("The file could not be read!");
					return;
				}

				// Clear all the lists
				_selectedRules.Clear();
				_originals.Clear();
				_previews.Clear();

				// Format:
				// PluginPreset={full_path_to_preset_file}
				// DestinationFolder={full_path_to_destination_folder}
				// Files={number_of_files}
				// {full_path_to_file_1}
				// {full_path_to_file_2}
				// ...

				// Get destination folder
				string destinationFolder = lines[1].Split('=')[1];
				if (destinationFolder != null && destinationFolder != "")
				{
					destinationFolderFullPath = destinationFolder;
					moveToAnotherFolderCheckBox.IsChecked = true;
					destinationFolderPathTextBox.Text = destinationFolderFullPath;
				}
				else
				{
					destinationFolderFullPath = "";
					moveToAnotherFolderCheckBox.IsChecked = false;
					destinationFolderPathTextBox.Text = "";
				}
				
				// Load file directories to _originals
				int numFiles = int.Parse(lines[2].Split('=')[1]);
				for (int i = 0; i < numFiles; i++)
				{
					_originals.Add(new { FullPath = lines[i + 3], FileName = Path.GetFileName(lines[i + 3]), ItemIndex = i });
				}

				// Get rule preset file
				// Note: Get last so that preview can be updated
				string rulePreset = lines[0].Split('=')[1];
				if (rulePreset != null && rulePreset != "")
				{
					// Load rule preset
					LoadRulePreset(rulePreset);
				}
			}
		}

		private void saveProjectButton_Click(object sender, RoutedEventArgs e)
		{
			CommonOpenFileDialog dialog = new CommonOpenFileDialog();
			
			dialog.InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);
			dialog.IsFolderPicker = true;
			
			if (dialog.ShowDialog() == CommonFileDialogResult.Ok)
			{
				// Save the current working state to a plain text file with the following format:
				// PluginPreset={full_path_to_preset_file}
				// DestinationFolder={full_path_to_destination_folder}
				// Files={number_of_files}
				// {full_path_to_file_1}
				// {full_path_to_file_2}
				// ...
			
				// Create a new file with the name of the current date and time
				string projectPath = $"{dialog.FileName}\\{DateTime.Now.ToString("yyyy-MM-dd_HH-mm-ss")}.txt";
				File.Create(projectPath).Close();
				
				// Write the current working state to the file
				using (StreamWriter sw = new StreamWriter(projectPath))
				{
					sw.WriteLine($"PluginPreset={ rulePresetFileFullPath }");
					if (destinationFolderFullPath != "" && moveToAnotherFolderCheckBox.IsChecked == true) sw.WriteLine($"DestinationFolder={destinationFolderFullPath}");
					else sw.WriteLine($"DestinationFolder=");
					sw.WriteLine($"Files={_originals.Count}");
					foreach (dynamic item in _originals)
					{
						sw.WriteLine(item.FullPath);
					}
				}
				
				MessageBox.Show($"Project file saved to {projectPath}");
			}
		}
	}
}