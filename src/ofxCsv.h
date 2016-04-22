/**
 *  ofxCsv.h
 *  Inspired and based on Ben Fry's [table class](http://benfry.com/writing/map/Table.pde)
 *
 *  The MIT License
 *
 *  Copyright (c) 2011-2014 Paul Vollmer, http://www.wng.cc
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 *
 *  @modified           2015.04.21
 *  @version            0.2.0
 */

#pragma once

#include "ofxCsvRow.h"

/// \class ofxCsv
/// \brief table data loaded from & saved to CSV (Character Separated Value) files
///
/// Parsing notes:
///   * Field whitespace & quoted field whitespace is preserved.
///   * Leading/trailing whitespace can be trimmed after loading.
///   * Quoted string quotes are trimmed upon loading, ie. "hello" -> hello
///   * Quoted quotes from Excel are preserved, ie ""hello"" -> "hello".
///
/// Saving notes:
///   * Fields are saved without quotes by default.
///   * ALL Fields can be quoted if desired, ie. 1.23 -> "1.23"
///
/// See https://en.wikipedia.org/wiki/Comma-separated_values for format info.
///
class ofxCsv {
	
	public:
	
		/// Constructor. Initializes and starts the class.
		ofxCsv();
	
	/// \section File IO

		/// Load a CSV File.
		///
		/// Clears any currently loaded data and sets the current path,
		/// fieldSeparator, & commentPrefix.
		///
		/// \param path File path to load.
		/// \param separator Field separator string, default ",".
		/// \param comment Comment line prefix string, default "#".
		/// \returns true if file loaded successfully
		bool load(string path, string separator, string comment);
	
		/// Load a CSV File.
		///
		/// Clears any currently loaded data and sets the current path &
		/// fieldSeparator.
		///
		/// Uses the current comment line prefix string.
		///
		/// \param path File path to load.
		/// \param separator Field separator string, default ",".
		/// \returns true if file loaded successfully
		bool load(string path, string separator);
	
		/// Load a CSV File.
		///
		/// Clears any currently loaded data and sets the current path.
		///
		/// Uses the current field separator & comment line prefix.
		///
		/// \param path File path to load. Leave empty to load current file.
		/// \returns true if file loaded successfully
		bool load(string path="");
	
		/// Save a CSV file.
		///
		/// \param filePath File path to save.
		/// \param quote Should the fields be double quoted? default false.
		/// \param separator Field separator string, default ",".
		/// \returns true if file saved successfully
		bool save(string path, bool quote, string separator);
	
		/// Save a CSV file.
		///
		/// Uses the current field separator.
		///
		/// \param filePath File path to save.
		/// \param quote Should the fields be double quoted? default false.
		/// \returns true if file saved successfully
		bool save(string path, bool quote);
	
		/// Save a CSV file.
		///
		/// Uses the current field separator & saves the fields without quotes.
		///
		/// \param path File path to save. Leave empty to save current file.
		/// \returns true if file saved successfully
		bool save(string path="");
	
		/// Create an empty CSV file.
		///
		/// \param path File path to create. Sets current file path.
		/// \returns true if file saved successfully
		bool createFile(string path);
	
	/// \section Data IO
	
		/// Load from a vector of rows.
		///
		/// Clears any currently loaded data.
		///
		/// \param rows Rows to load.
		void load(vector<ofxCsvRow> &rows);
	
		/// Load from a vector of row strings.
		///
		/// Clears any currently loaded data.
		///
		/// \param rows Rows to load.
		void load(vector<vector<string>> &rows);
	
		/// Add a row to the end.
		///
		/// \param row Row to append.
		void add(ofxCsvRow &row);
	
		/// Insert a row at a given position.
		///
		/// Expands to fit the required number of rows
		///
		/// \param row Row to insert.
		/// \param index Desired position.
		void insert(ofxCsvRow &row, int index);
	
		/// Remove a row at a given position.
		///
		/// \param index Position of row to remove.
		void remove(int index);
	
		/// Expand for the required number of rows and cols.
		///
		/// Fills any missing fields with empty strings.
		///
		/// \param rows Number of desired rows.
		/// \param cols Number of desired columns.
		void expand(int rows, int cols);
	
		/// Clear the current row and column data.
		void clear();
	
	/// \section Data Access
	
		/// Get the current number of rows.
		/// \returns the current number of rows
		unsigned int getNumRows();
	
		/// Get the current number of cols for a given row.
		///
		/// \param row Row to get the number of cols for, default: 0.
		/// \returns the number of cols in the given row or 0 if the row does not exist.
		unsigned int getNumCols(int row=0);
	
		/// Get a field as an integer value.
		///
		/// \param row Row number
		/// \param col Column number
		/// \returns the value or 0 if not found.
		int getInt(int row, int col);
	
		/// Get a field as a float value.
		///
		/// \param row Row number
		/// \param col Column number
		/// \returns the value or 0.0 if not found.
		float getFloat(int row, int col);
	
		/// Get a field as a string value.
		///
		/// \param row Row number
		/// \param col Column number
		/// \returns the value or "" if not found.
		string getString(int row, int col);
	
		/// Get a field as a boolean value.
		///
		/// \param row Row number
		/// \param col Column number
		/// \returns the value or false if not found.
		bool getBool(int row, int col);
	
		//// Set a field to an integer value.
		///
		/// Expands number of rows and/or cols to fit required field.
		///
		/// \param row Row number
		/// \param col Column number
		/// \param what Value to set
		void setInt(int row, int col, int what);
	
		//// Set a field to a float value.
		///
		/// Expands number of rows and/or cols to fit required field.
		///
		/// \param row Row number
		/// \param col Column number
		/// \param what Value to set
		void setFloat(int row, int col, float what);
	
		//// Set a field to a string value.
		///
		/// Expands number of rows and/or cols to fit required field.
		///
		/// \param row Row number
		/// \param col Column number
		/// \param what Value to set
		void setString(int row, int col, string what);
	
		//// Set a field to a boolean value.
		///
		/// Expands number of rows and/or cols to fit required field.
		///
		/// \param row Row number
		/// \param col Column number
		/// \param what Value to set
		void setBool(int row, int col, bool what);
	
		/// Print the current data to the console.
		void print();
	
	/// \section Raw Data Access
	
		// iterator wrappers for easy looping:
		//
		//     ofxCsv csv;
		//     csv.load("file.csv");
		//     for(auto row : csv) {
		//       // do something for each row
		//     }
		//
		vector<ofxCsvRow>::iterator begin();
		vector<ofxCsvRow>::iterator end();
		vector<ofxCsvRow>::const_iterator begin() const;
		vector<ofxCsvRow>::const_iterator end() const;
		vector<ofxCsvRow>::reverse_iterator rbegin();
		vector<ofxCsvRow>::reverse_iterator rend();
		vector<ofxCsvRow>::const_reverse_iterator rbegin() const;
		vector<ofxCsvRow>::const_reverse_iterator rend() const;
	
		/// Use as a vector of rows.
		operator vector<ofxCsvRow>() const;
	
		/// Raw string data access via row array indices.
		ofxCsvRow operator[](size_t index);
	
		/// Raw string data access via index.
		ofxCsvRow at(size_t index);
	
		/// Get the first row, like vector.
		ofxCsvRow front();
	
		/// Get the last row, like vector.
		ofxCsvRow back();
	
		/// Alternate row size getter.
		size_t size();
	
	/// \section Util
	
		/// Trim leading & trailing whitespace from all non-quoted fields.
		void trim();
	
		/// Split a row string into fields.
		///
		/// \param row Row string to split.
		/// \param separator Field separator string, default ",".
		/// \returns String vector of fields.
		vector<string> fromRowString(string row, string separator);
	
		/// Split a row string into fields.
		///
		/// Uses the current field separator.
		///
		/// \param row Row string to split.
		/// \returns String vector of fields.
		vector<string> fromRowString(string row);
	
		/// Join a row of separate column fields into a single string.
		///
		/// \param row Fields to join.
		/// \param separator Field separator string, default ",".
		/// \param quote Should the fields be double quoted? default false.
		/// \returns The row as a single string.
		string toRowString(vector<string> row, string separator, bool quote);
	
		/// Join a row of separate column fields into a single string.
		///
		/// Quotes the fields.
		///
		/// \param row Fields to join.
		/// \param separator Field separator string, default ",".
		/// \returns The row as a single string.
		string toRowString(vector<string> cols, string separator);
	
		/// Join a row of separate column fields into a single string.
		///
		/// Uses the current field separator & does not quote the fields.
		///
		/// \param row Fields to join.
		/// \returns The row as a single string.
		string toRowString(vector<string> cols);
	
		/// Get the current file path.
		string getPath();
	
		/// Get the field seaprator, default: comma ","
		string getFieldSeparator();
	
		/// Get the current comment line prefix, default: "#"
		string getCommentPrefix();
	
	protected:
	
		/// Expand to include a required row.
		///
		/// Fills any missing fields in this row with empty strings.
		///
		/// \param rows Row to expand to
		/// \param cols Number of desired columns in the row.
		void expandRow(int row, int cols);
	
		/// row data
		vector<ofxCsvRow> data;
	
		string filePath;       //< Current file path
		string fieldSeparator; //< Field separator, default: comma ","
		string commentPrefix;  //< Comment line prefix, default: "#"
		bool quoteFields;      //< Save double quoted fields? default false
};
