/*
 Navicat Premium Data Transfer

 Source Server         : local
 Source Server Type    : MySQL
 Source Server Version : 50540
 Source Host           : localhost:3306
 Source Schema         : demo

 Target Server Type    : MySQL
 Target Server Version : 50540
 File Encoding         : 65001

 Date: 16/05/2023 20:18:37
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for admin
-- ----------------------------
DROP TABLE IF EXISTS `admin`;
CREATE TABLE `admin`  (
  `admin_id` int(10) NOT NULL DEFAULT 0 COMMENT '管理员id',
  `admin_name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '管理员姓名',
  `admin_password` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '管理员密码',
  PRIMARY KEY (`admin_id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of admin
-- ----------------------------
INSERT INTO `admin` VALUES (101, '张三', '011');
INSERT INTO `admin` VALUES (102, '李四 ', '022');

-- ----------------------------
-- Table structure for application
-- ----------------------------
DROP TABLE IF EXISTS `application`;
CREATE TABLE `application`  (
  `application_id` int(15) NOT NULL COMMENT '编号',
  `application_num` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '申请人id',
  `application_name` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '申请人',
  `application_time` datetime NULL DEFAULT NULL COMMENT '申请时间',
  `application_room` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '申请教室',
  `application_reason` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '申请原因',
  PRIMARY KEY (`application_id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of application
-- ----------------------------
INSERT INTO `application` VALUES (1, '11001', '马老师', '2023-05-16 20:15:35', '教室5', '班级会议');
INSERT INTO `application` VALUES (2, '20011', '王老师', '2023-05-16 20:16:05', '教室3', '教师授课');
INSERT INTO `application` VALUES (3, '30131', '刘老师', '2023-05-16 20:16:31', '教室10', '教师授课');
INSERT INTO `application` VALUES (4, '20080503', '小赵', '2023-05-16 20:17:04', '教室9', '学生活动');
INSERT INTO `application` VALUES (5, '20130101', '小王', '2023-05-16 20:17:32', '教室7', '学生活动');
INSERT INTO `application` VALUES (6, '20130911', '小皇', '2023-05-16 20:17:56', '多功能放映厅', '观看《感动中国》');

-- ----------------------------
-- Table structure for classroom
-- ----------------------------
DROP TABLE IF EXISTS `classroom`;
CREATE TABLE `classroom`  (
  `classroom_id` int(30) NOT NULL DEFAULT 0 COMMENT '教室信息id',
  `classroom_name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '教室名称',
  `classroom_type` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '教室类型',
  `classroom_seat` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '教室位置',
  `classroom_status` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '教室目前状态',
  `classroom_introduce` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '教室介绍',
  PRIMARY KEY (`classroom_id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of classroom
-- ----------------------------
INSERT INTO `classroom` VALUES (1, '教室1', '一号教学楼', '1-301', '占用', '容量170');
INSERT INTO `classroom` VALUES (2, '教室2', '一号教学楼', '3-104', '空闲', '容量180');
INSERT INTO `classroom` VALUES (3, '教室3', '二号教学楼', '3-116', '空闲', '容量180');
INSERT INTO `classroom` VALUES (4, '教室4', '二号教学楼', '1-207', '空闲', '容量150');
INSERT INTO `classroom` VALUES (5, '教室5', '三号教学楼', '2-116', '空闲', '容量180');
INSERT INTO `classroom` VALUES (6, '教室6', '三号教学楼', '3-411', '占用', '容量160');
INSERT INTO `classroom` VALUES (7, '教室7', '一号实验楼', '2-507', '空闲', '容量80');
INSERT INTO `classroom` VALUES (8, '教室8', '一号实验楼', '1-411', '空闲', '容量80');
INSERT INTO `classroom` VALUES (9, '教室9', '二号实验楼', '1-213', '空闲', '容量70');
INSERT INTO `classroom` VALUES (10, '教室10', '二号实验楼', '2-116', '空闲', '容量80');
INSERT INTO `classroom` VALUES (11, '教室11', '三号实验楼', '2-211', '空闲', '容量70');
INSERT INTO `classroom` VALUES (12, '教室12', '三号实验楼', '3-408', '占用', '容量60');
INSERT INTO `classroom` VALUES (13, '教室13', '多功能放映厅', '多功能放映厅', '空闲', '容量60');
INSERT INTO `classroom` VALUES (14, '教室14', '求是堂', '求是堂', '空闲', '容量200');
INSERT INTO `classroom` VALUES (15, '教室15', '共享空间', '共享空间', '空闲', '容量150');
INSERT INTO `classroom` VALUES (16, '教室16', '值班室', '值班室', '空闲', '容量30');

-- ----------------------------
-- Table structure for student
-- ----------------------------
DROP TABLE IF EXISTS `student`;
CREATE TABLE `student`  (
  `student_number` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT '学号',
  `full_name` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '姓名',
  `gender` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '性别',
  `password` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '密码',
  `Professional Class` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '专业班级',
  `information` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '联系方式',
  PRIMARY KEY (`student_number`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of student
-- ----------------------------
INSERT INTO `student` VALUES ('20020201', '小郭', '男', '0201', '法医学02班', '13048651169');
INSERT INTO `student` VALUES ('20020301', '小蔡', '男', '0301', '法医学03班', '16322001123');
INSERT INTO `student` VALUES ('20020403', '小八', '男', '0403', '法医学04班', '15233445678');
INSERT INTO `student` VALUES ('20020511', '小康', '男', '0511', '法医学05班', '12330111234');
INSERT INTO `student` VALUES ('20080411', '小李', '男', '0411', '会计学04班', '13011060071');
INSERT INTO `student` VALUES ('20080503', '小赵', '女', '0503', '会计学05班', '13044521197');
INSERT INTO `student` VALUES ('20080613', '小猪', '男', '0613', '会计学06班', '13411220212');
INSERT INTO `student` VALUES ('20080618', '小白', '女', '0618', '会计学06班', '11222220101');
INSERT INTO `student` VALUES ('20080708', '小年', '男', '0708', '会计学07班', '13044101010');
INSERT INTO `student` VALUES ('20080813', '小米', '男', '0813', '会计学08班', '17233110202');
INSERT INTO `student` VALUES ('20130101', '小王', '男', '0101', '计算机科学与技术01班', '13091241136');
INSERT INTO `student` VALUES ('20130203', '小路', '女', '0203', '计算机科学与技术02班', '13045681124');
INSERT INTO `student` VALUES ('20130310', '小豆', '男', '0310', '计算机科学与技术03班', '17655423310');
INSERT INTO `student` VALUES ('20130408', '小茹', '女', '0408', '计算机科学与技术04班', '17644301121');
INSERT INTO `student` VALUES ('20130512', '小芳', '女', '0512', '计算机科学与技术05班', '17610022231');
INSERT INTO `student` VALUES ('20130621', '小丽', '女', '0621', '计算机科学与技术06班', '13011249901');
INSERT INTO `student` VALUES ('20130701', '小肖', '男', '0701', '计算机科学与技术07班', '17233401122');
INSERT INTO `student` VALUES ('20130803', '小黎', '男', '0803', '计算机科学与技术08班', '16311542231');
INSERT INTO `student` VALUES ('20130911', '小皇', '男', '0911', '计算机科学与技术09班', '17233144444');
INSERT INTO `student` VALUES ('20131002', '小玛', '男', '1002', '计算机科学与技术10班', '15544223333');

-- ----------------------------
-- Table structure for teacher
-- ----------------------------
DROP TABLE IF EXISTS `teacher`;
CREATE TABLE `teacher`  (
  `teacher_id` int(11) NOT NULL DEFAULT 0 COMMENT '教师工号',
  `full_name` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '姓名',
  `gender` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '性别',
  `position` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '职称',
  `teacher_password` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT 'password',
  `information` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '联系电话',
  PRIMARY KEY (`teacher_id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of teacher
-- ----------------------------
INSERT INTO `teacher` VALUES (10043, '李老师', '女', '讲师', '100431', '14560011230');
INSERT INTO `teacher` VALUES (11001, '马老师', '男', '讲师', '110011', '17600211121');
INSERT INTO `teacher` VALUES (12003, '黎老师', '女', '教授', '120031', '13011223300');
INSERT INTO `teacher` VALUES (13001, '肖老师', '男', '教授', '130011', '13011564411');
INSERT INTO `teacher` VALUES (20011, '王老师', '男', '讲师', '200111', '17645001203');
INSERT INTO `teacher` VALUES (20111, '颂老师', '男', '副教授', '201111', '13022130014');
INSERT INTO `teacher` VALUES (30131, '刘老师', '男', '教授', '301311', '18534012230');

-- ----------------------------
-- Table structure for tel
-- ----------------------------
DROP TABLE IF EXISTS `tel`;
CREATE TABLE `tel`  (
  `tel_id` int(30) NOT NULL DEFAULT 0 COMMENT '公告id',
  `tel_publisher` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '发布者',
  `tel_content` varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '内容',
  `tel_time` datetime NOT NULL COMMENT '发布时间',
  PRIMARY KEY (`tel_id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of tel
-- ----------------------------
INSERT INTO `tel` VALUES (1, '张三', '一号教学楼3-104目前正在维修，无法申请', '2023-04-10 20:00:10');
INSERT INTO `tel` VALUES (2, '张三', '三号教学楼3-411监控设备升级，无法申请', '2023-04-10 20:00:59');
INSERT INTO `tel` VALUES (3, '张三', '一号实验楼1-411实验设备损坏，无法申请', '2023-05-16 19:44:31');
INSERT INTO `tel` VALUES (4, '李四', '多功能放映厅放映设备损坏，无法申请', '2023-05-16 19:45:25');

SET FOREIGN_KEY_CHECKS = 1;
