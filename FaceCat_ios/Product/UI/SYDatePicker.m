/*
 * FaceCat图形通讯框架
 * 上海卷卷猫信息技术有限公司
 */

#import "SYDatePicker.h"

@implementation SYDatePicker

- (void)showInView:(UIView *)view withFrame:(CGRect)frame andDatePickerMode:(UIDatePickerMode)mode{
    self.frame = frame;
    self.backgroundColor = [UIColor whiteColor];
    
    if(!self.picker){
        self.picker = [[UIDatePicker alloc] initWithFrame:CGRectMake(0, 46, frame.size.width, frame.size.height - 38)];
    }
    //[self.picker setTimeZone:[NSTimeZone timeZoneForSecondsFromGMT:8]];
    self.picker.datePickerMode = mode;
    if(self.dates)
    {
        self.picker.date = self.dates;
    }
    [self.picker addTarget:self action:@selector(valueChanged:) forControlEvents:UIControlEventValueChanged];
    [self addSubview:self.picker];
    
    UIButton *btnDone = [UIButton buttonWithType:UIButtonTypeSystem];
    btnDone.frame = CGRectMake(8, 8, 50, 30);
    [btnDone setTitle:@"完成" forState:UIControlStateNormal];
    [btnDone addTarget:self action:@selector(pickDone) forControlEvents:UIControlEventTouchUpInside];
    [self addSubview:btnDone];
    [view addSubview:self];
    
    self.frame = CGRectMake(0, kScreen_Height, kScreen_Width, 0);
    
    [UIView animateWithDuration:0.3 animations:^{
        self.frame = frame;
    }];
}

- (void)pickDone{
    if (![self.picker respondsToSelector:@selector(valueChanged:)]) {
        [self.delegate picker:self.picker ValueChanged:self.picker.date];
    }
    [self dismiss];
}

- (void)dismiss{
    [UIView animateWithDuration:0.3 animations:^{
         self.frame = CGRectMake(0, kScreen_Height, kScreen_Width, 0);
    } completion:^(BOOL finished) {
        [self removeFromSuperview];
    }];
}

- (void)valueChanged:(UIDatePicker *)picker{
    if([self.delegate respondsToSelector:@selector(picker:ValueChanged:)]){
        [self.delegate picker:picker ValueChanged:picker.date];
    }
}

@end
