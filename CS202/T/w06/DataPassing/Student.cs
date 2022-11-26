using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataPassing
{
    public class Student: INotifyPropertyChanged, ICloneable
    {
        public string ID { get; set; }
        public string Name { get; set; }
        public int Credits { get; set; }
        public string Avatar { get; set; }

        public event PropertyChangedEventHandler? PropertyChanged;

        public object Clone()
        {
            //Student sv = new Student();
            //sv.ID = this.ID;
            //sv.Name = this.Name;
            //sv.Credits = this.Credits;
            //sv.Avatar = this.Avatar;
            //return sv;
                
            return MemberwiseClone();
        }
    }
}
