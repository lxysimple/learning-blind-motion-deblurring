"""
运行该脚本，自动生成videos_test_1/videos_test_2/...数据集下所有的视频人工模糊后的所有帧
保存在 /media/lxy/新加卷/Ubuntu/300vw_myblur/" + video_id 下
"""

import os


# 300vw一共有这么多视频，每个视频都用一个文件夹装着
videos_all =  ['001', '002', '003', '004', '007', '009', '010', '011', '013', '015', 
                    '016', '017', '018', '019', '020', '022', '025', '027', '028', '029', 
                    '031', '033', '034', '035', '037', '039', '041', '043', '044', '046', 
                    '047', '048', '049', '053', '057', '059', '112', '113', '114', '115', 
                    '119', '120', '123', '124', '125', '126', '138', '143', '144', '150', 
                    '158', '160', '203', '204', '205', '208', '211', '212', '213', '214', 
                    '218', '223', '224', '225', 
                                                '401', '402', '403', '404', '405', '406', 
                    '407', '408', '409', '410', '411', '412', '505', '506', '507', '508', 
                    '509', '510', '511', '514', '515', '516', '517', '518', '519', '520', 
                    '521', '522', '524', '525', '526', '528', '529', '530', '531', '533', 
                    '537', '538', '540', '541', '546', '547', '548', '550', '551', '553', 
                    '557', '558', '559', '562']

# Category 1 in laboratory and naturalistic well-lit conditions
videos_test_1 = ['114', '124', '125', '126', '150', '158', '401', '402', '505', '506',
                        '507', '508', '509', '510', '511', '514', '515', '518', '519', '520', 
                        '521', '522', '524', '525', '537', '538', '540', '541', '546', '547', 
                        '548']
# Category 2 in real-world human-computer interaction applications
videos_test_2 = ['203', '208', '211', '212', '213', '214', '218', '224', '403', '404', 
                        '405', '406', '407', '408', '409', '412', '550', '551', '553']

# Category 3 in arbitrary conditions
videos_test_3 = ['410', '411', '516', '517', '526', '528', '529', '530', '531', '533', 
                        '557', '558', '559', '562']

videos_train = [ i for i in videos_all if i not in videos_test_1 
                                        and i not in videos_test_2 
                                        and i not in videos_test_3]


for i in videos_test_2:

    pic_dir = f"/media/lxy/新加卷/Ubuntu/300vw_myblur/{i}"
    if not os.path.exists(pic_dir):
        os.makedirs(pic_dir)

    os.system('cd /home/lxy/learning-blind-motion-deblurring')
    os.system(f'./synthblur/build/convert "/media/lxy/新加卷/mmpose/data/300VW_Dataset_2015_12_14/{i}/vid.avi" "{i}"')
