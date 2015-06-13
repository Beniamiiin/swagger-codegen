#import <Foundation/Foundation.h>
#import "SWGOrder.h"
#import "SWGObject.h"
#import "SWGApiClient.h"


@interface SWGStoreApi: NSObject

@property(nonatomic, assign)SWGApiClient *apiClient;

-(instancetype) initWithApiClient:(SWGApiClient *)apiClient;
-(void) addHeader:(NSString*)value forKey:(NSString*)key;
-(unsigned long) requestQueueSize;
+(SWGStoreApi*) apiWithHeader:(NSString*)headerValue key:(NSString*)key;
+(void) setBasePath:(NSString*)basePath;
+(NSString*) getBasePath;
//
//
// Returns pet inventories by status
// Returns a map of status codes to quantities
//
// 
//
// @return NSDictionary* /* NSString, NSNumber */
-(NSNumber*) getInventoryWithCompletionBlock :
    (void (^)(NSDictionary* /* NSString, NSNumber */ output, NSError* error))completionBlock;
    


//
//
// Place an order for a pet
// 
//
// @param body order placed for purchasing the pet
// 
//
// @return SWGOrder*
-(NSNumber*) placeOrderWithCompletionBlock :(SWGOrder*) body 
    
    completionHandler: (void (^)(SWGOrder* output, NSError* error))completionBlock;
    


//
//
// Find purchase order by ID
// For valid response try integer IDs with value <= 5 or > 10. Other values will generated exceptions
//
// @param orderId ID of pet that needs to be fetched
// 
//
// @return SWGOrder*
-(NSNumber*) getOrderByIdWithCompletionBlock :(NSString*) orderId 
    
    completionHandler: (void (^)(SWGOrder* output, NSError* error))completionBlock;
    


//
//
// Delete purchase order by ID
// For valid response try integer IDs with value < 1000. Anything above 1000 or nonintegers will generate API errors
//
// @param orderId ID of the order that needs to be deleted
// 
//
// @return 
-(NSNumber*) deleteOrderWithCompletionBlock :(NSString*) orderId 
    
    
    completionHandler: (void (^)(NSError* error))completionBlock;



@end
