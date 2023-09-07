using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MongoDB.Bson;
using MongoDB.Bson.Serialization.Attributes;

namespace PAWProiectFinal
{
    internal class Produs : ICloneable, IComparable
    {
        [BsonId]
        [BsonRepresentation(BsonType.ObjectId)]
        public string _id { get; set; }

        public string Nume { get; set; }
        public int Cantitate { get; set; }
        public int Pret { get; set; }

        /*public Produs()
        {
            Nume = string.Empty;
            Cantitate = 0;
            Pret = 0;
        }

        public Produs(int id, string nume, int cantitate, int pret)
        {
            Nume = nume;
            Cantitate = cantitate;
            Pret = pret;
        }*/

        public int Valoare()
        {
            return Cantitate * Pret;
        }

        object ICloneable.Clone()
        {
            return this.MemberwiseClone();
        }

        public Produs Clone()
        {
            return (Produs)((ICloneable)this).Clone();
        }

        int IComparable.CompareTo(object obj)
        {
            Produs P = obj as Produs;
            if (this.Valoare() > P.Valoare()) { return 1; }
            else if (this.Valoare() > P.Valoare()) { return -1; }
            else { return 0; }
        }

        public static Produs operator +(Produs P, int V)
        {
            Produs Copie = new Produs(); Copie = P.Clone();
            Copie.Cantitate = Copie.Cantitate + V;
            return Copie;
        }

        public static Produs operator -(Produs P, int V)
        {
            Produs Copie = new Produs(); Copie = P.Clone();
            Copie.Cantitate = Copie.Cantitate - V;
            return Copie;
        }

        public static Produs operator ++(Produs P)
        {
            Produs Copie = new Produs(); Copie = P.Clone();
            Copie.Pret++;
            return Copie;
        }

        public static Produs operator --(Produs P)
        {
            Produs Copie = new Produs(); Copie = P.Clone();
            Copie.Pret--;
            return Copie;
        }

        public override string ToString()
        {
            return this.Nume + " - " + this.Cantitate + " - " + this.Pret;
        }
    }
}
