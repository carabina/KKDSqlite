//
//  SqliteBaseData.h
//  KKDSqlite
//
//  Created by Kadir Kemal Dursun on 26/07/2017.
//  Copyright © 2017 Kadir Kemal Dursun. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol DBIgnore
@end

/*
@protocol DBNullableColumn
@end

@protocol DBKeyColumn
@end
*/
 
@interface SqliteBaseData : NSObject

/*!
 @brief The name of the databse table. It should be overriden.
 */
+(NSString *) tableName;

/*!
 @brief The method generates a sql command by using params. Params keys should be one of the column names in the table. The generated creates SqliteBaseData instance array by executing the generated command on database.
 
 @param command the sql command that will be executed
 */
+(NSMutableArray <SqliteBaseData*>*) modelListFromDB:(NSDictionary *) params;

/*!
 @brief The method generates a sql command by using params and orderBy.  Params keys and orderBy should be one of the column names in the table. The generated creates SqliteBaseData instance array by executing the generated command on database.
 
 @param command the sql command that will be executed
 */
+(NSMutableArray <SqliteBaseData*>*) modelListFromDB:(NSDictionary *) params orderBy:(NSString*) orderBy;

/*!
 @brief The method creates SqliteBaseData instance array by executing the command on database.
 
 @param command the sql command that will be executed
 */
+(NSMutableArray <SqliteBaseData*>*) modelListWithCommand:(NSString *) command;




@property int id;
@property (nonatomic)id primaryColumnValue;


/*!
 @brief Selects the row from class table and initializes the instance that's primary key is 'id'
 */
-(instancetype) initWithId:(int) id;

/*!
 @brief default value is 'id'
 */
-(NSString *) primaryColumnName;

/*!
 @brief returns the value of primary key
 */
-(NSNumber *) primaryColumnValue;

/*!
 @brief resets value of primary column, default is setting zero
 */
-(void)resetPrimaryColumnValue;

/*!
 @brief YES, if the instance has not been saved to database.
 */
-(BOOL)isNew;

-(NSMutableDictionary *) columnValues;
-(NSMutableDictionary *) columnValuesExceptPrimary;

/*!
 @brief This method binds the instance to its parent. For example, if the instance has parentId field, this field should be set in this method by using the input patameter parent.
 
@param  parent The parent instance of self
  */
-(void) bindToParent:(SqliteBaseData *) parent;

/*!
 @brief This method saves the instance to database.
 
 @return if self is saved succesfully, it returns YES, otherwise NO.
 */
-(BOOL)saveMe;

/*!
 @brief This method deletes the instance from database.
 
 @return if self is deleted succesfully, it returns YES, otherwise NO.
 */
-(BOOL)deleteMe;

/*!
 @brief This method saves the instance and the instances in dataList to database in a same transaction. If one of the saving process fails, the other saving processes are rolled back.
 
 @param  dataList The SqliteBaseData instance array that will be saved with self
 
 @return If all of the instances are saved successfully, it returns YES, otherwise it returns NO
 */
-(BOOL)saveMeWith:(NSArray <SqliteBaseData*>*) dataList;

/*!
 @brief This method saves the instance and the instances in dataList to database in a same transaction. Firstly, self is saved. 'bindToParent' method is called for every instance in the dataList before saving. If one of the saving process fails, the other saving processes are rolled back.
 
 @param  dataList The SqliteBaseData instance array that will be saved with self
 
 @return If all of the instances are saved successfully, it returns YES, otherwise it returns NO
 */
-(BOOL)saveMeWithChildren:(NSArray <SqliteBaseData*>*) dataList;

/*!
 @brief This method deletes the instance and the instances in dataList from database in a same transaction. If one of the deleting process fails, the other deleting processes are rolled back.
 
 @param  dataList The SqliteBaseData instance array that will be deleted with self
 
 @return If all of the instances are deleted successfully, it returns YES, otherwise it returns NO
 */
-(BOOL)deleteMeWith:(NSArray <SqliteBaseData*>*) dataList;

@end